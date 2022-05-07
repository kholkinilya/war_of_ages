#include "../../include/screens/start_screen.h"
#include "../../include/client.h"
#include "../../include/screen_handler.h"
#include "../../include/ui_functions.h"

// TGUI widgets
#include <TGUI/Widgets/Button.hpp>
#include <TGUI/Widgets/Group.hpp>
#include "../../include/application.h"
#include "../../include/sound_player.h"

namespace war_of_ages {
void start_screen_init(tgui::Gui &gui) {
    auto start_screen_group = tgui::Group::create();

    tgui::Button::Ptr singleplayer_button = tgui::Button::create("Одиночная игра");
    singleplayer_button->setTextSize(30);
    singleplayer_button->onPress([&gui]() {
        application::instance().set_state(application::state::SINGLE_PLAYER_GAME);
        screen_handler::instance().change_screen(screen_handler::screen_type::GAME_SCREEN);
        sound_player::instance().change(sound_player::sound_type::LOBBY, sound_player::sound_type::BATTLE);
        current_state.create_game(client_state::game_mode::SINGLE);
    });
    start_screen_group->add(singleplayer_button);

    tgui::Button::Ptr multiplayer_button = tgui::Button::create("Мультиплеер");
    multiplayer_button->setTextSize(30);
    multiplayer_button->onPress([&gui]() {
        screen_handler::instance().change_screen(screen_handler::screen_type::MULTIPLAYER);
        current_state.create_game(client_state::game_mode::MULTI);
    });
    start_screen_group->add(multiplayer_button);

    tgui::Button::Ptr tournament_button = tgui::Button::create("Турниры");
    tournament_button->setTextSize(30);
    tournament_button->onPress([&gui]() {
        screen_handler::instance().change_screen(screen_handler::screen_type::TOURNAMENT_JOINING);
    });
    start_screen_group->add(tournament_button);

    tgui::Button::Ptr statistics_button = tgui::Button::create("Статистика");
    statistics_button->setTextSize(30);
    // TODO: onPress: switch to the statistics screen when it is implemented
    start_screen_group->add(statistics_button);

    tgui::Button::Ptr exit_button = tgui::Button::create("Выйти");
    exit_button->setTextSize(30);
    exit_button->onPress(exit, 0);  // FIXME: Implement closing app in the other way
    start_screen_group->add(exit_button);

    std::vector<tgui::Widget::Ptr> widgets{singleplayer_button, multiplayer_button, tournament_button,
                                           statistics_button, exit_button};
    place_widgets(widgets);

    tgui::Button::Ptr settings_screen_button = tgui::Button::create();
    settings_screen_button->getRenderer()->setTexture("../client/resources/pictures/settings_icon.png");
    settings_screen_button->getRenderer()->setBorders(0);
    settings_screen_button->setSize("4.5%", "8%");
    settings_screen_button->setPosition("90%", "5%");
    settings_screen_button->onPress(
        [&gui]() { screen_handler::instance().change_screen(screen_handler::screen_type::SETTINGS); });
    start_screen_group->add(settings_screen_button);

    gui.add(start_screen_group, screen_handler::screen_id.at(screen_handler::screen_type::START_SCREEN));
    gui.get(screen_handler::screen_id.at(screen_handler::screen_type::START_SCREEN))->setVisible(false);
}
}  // namespace war_of_ages