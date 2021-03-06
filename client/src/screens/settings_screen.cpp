#include "application.h"
#include "client.h"
#include "screen_handler.h"
#include "sfml_printer.h"
#include "single_player_handler.h"
#include "sound_player.h"
#include "messages_type.h"

// TGUI widgets
#include <TGUI/Widgets/Button.hpp>
#include <TGUI/Widgets/Group.hpp>
#include <TGUI/Widgets/Label.hpp>
#include <TGUI/Widgets/Slider.hpp>

namespace war_of_ages::client {
void screen_handler::settings_screen_init() {
    auto settings_screen_group = tgui::Group::create();

    tgui::Theme black_theme("../../client/resources/tgui_themes/Black.txt");

    tgui::Label::Ptr battle_music_volume_label = tgui::Label::create("Громкость музыки в бою");
    tgui::Label::Ptr battle_sounds_volume_label = tgui::Label::create("Громкость звуков в бою");
    tgui::Label::Ptr lobby_music_volume_label = tgui::Label::create("Громкость музыки в лобби");
    battle_music_volume_label->setTextSize(25);
    battle_sounds_volume_label->setTextSize(25);
    lobby_music_volume_label->setTextSize(25);
    battle_music_volume_label->getRenderer()->setTextColor("white");
    battle_sounds_volume_label->getRenderer()->setTextColor("white");
    lobby_music_volume_label->getRenderer()->setTextColor("white");
    battle_music_volume_label->setPosition("34%", "29%");
    battle_sounds_volume_label->setPosition("34%", "39%");
    lobby_music_volume_label->setPosition("34%", "49%");

    tgui::Slider::Ptr battle_music_volume_slider = tgui::Slider::create(0, 100);
    tgui::Slider::Ptr battle_sounds_volume_slider = tgui::Slider::create(0, 100);
    tgui::Slider::Ptr lobby_music_volume_slider = tgui::Slider::create(0, 100);
    battle_music_volume_slider->setRenderer(black_theme.getRenderer("Slider"));
    battle_sounds_volume_slider->setRenderer(black_theme.getRenderer("Slider"));
    lobby_music_volume_slider->setRenderer(black_theme.getRenderer("Slider"));
    battle_music_volume_slider->setPosition("54%", "30%");
    battle_sounds_volume_slider->setPosition("54%", "40%");
    lobby_music_volume_slider->setPosition("54%", "50%");

    battle_music_volume_slider->onValueChange([&battle_sounds_volume_slider](float new_value) {
        sound_player::instance().set_volume(sound_player::sound_type::BATTLE, new_value);
    });
    lobby_music_volume_slider->onValueChange([&lobby_music_volume_slider](float new_value) {
        sound_player::instance().set_volume(sound_player::sound_type::LOBBY, new_value);
    });
    battle_music_volume_slider->setValue(
        sound_player::instance().get_volume(sound_player::sound_type::BATTLE));
    // battle_sounds_volume_slider->setValue(50);
    lobby_music_volume_slider->setValue(sound_player::instance().get_volume(sound_player::sound_type::LOBBY));

    settings_screen_group->add(battle_music_volume_label);
    settings_screen_group->add(battle_sounds_volume_label);
    settings_screen_group->add(lobby_music_volume_label, "lobby_music_volume_label");
    settings_screen_group->add(battle_music_volume_slider);
    settings_screen_group->add(battle_sounds_volume_slider);
    settings_screen_group->add(lobby_music_volume_slider, "lobby_music_volume_slider");

    tgui::Button::Ptr resume_button = tgui::Button::create("Продолжить игру");
    resume_button->setRenderer(black_theme.getRenderer("Button"));
    resume_button->setTextSize(30);
    resume_button->onPress([&]() {
        if (application::instance().get_state() == application::state::SINGLE_PLAYER_GAME) {
            single_player_handler::instance().return_from_pause();
        }
        screen_handler::instance().change_screen(screen_handler::screen_type::GAME_SCREEN);
    });
    resume_button->setPosition("30%", "73%");
    resume_button->setSize("40%", "10%");
    settings_screen_group->add(resume_button, "resume_button");

    auto return_button = tgui::Button::create("В главное меню");
    return_button->setRenderer(black_theme.getRenderer("Button"));
    return_button->setTextSize(30);
    return_button->onPress([&]() {
        auto state = application::instance().get_state();
        if (state == application::state::MULTIPLAYER) {
            message<messages_type> msg;
            msg.header.id = messages_type::GAME_GIVE_UP;
            client::instance().send_message(msg);
        } else {
            application::instance().set_state(application::state::MENU);
            screen_handler::instance().change_screen(screen_handler::screen_type::START_SCREEN);
            if (state == application::state::SINGLE_PLAYER_GAME) {
                sound_player::instance().change(sound_player::sound_type::BATTLE,
                                                sound_player::sound_type::LOBBY);
            }
        }
    });
    return_button->setPosition("30%", "86%");
    return_button->setSize("40%", "10%");
    settings_screen_group->add(return_button, "return_button");

    m_gui.add(settings_screen_group, screen_handler::screen_id.at(screen_handler::screen_type::SETTINGS));
    m_gui.get(screen_handler::screen_id.at(screen_handler::screen_type::SETTINGS))->setVisible(false);
}
}  // namespace war_of_ages::client
