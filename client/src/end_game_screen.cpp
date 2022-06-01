#include "../include/end_game_screen.h"
#include "../include/bot_actions_receiver.h"
#include "../include/client.h"
#include "../include/ui_functions.h"

// TGUI widgets
#include <TGUI/Widgets/Button.hpp>
#include <TGUI/Widgets/Group.hpp>
#include <TGUI/Widgets/Label.hpp>

namespace war_of_ages {
void check_game_end(tgui::Gui &gui) {
    if (war_of_ages::current_state.get_cur_game_state() != nullptr &&
        war_of_ages::current_state.get_cur_game_state()->get_game_status() !=
            war_of_ages::game_status::PROCESSING) {
        if(current_state.get_counter() % 10 == 0) {
            std::cout << "Games played: " << current_state.get_counter() << std::endl;
            std::cout << "Positions reached: " << bot_actions_receiver::get_positions().size() << std::endl;
            std::cout << "=====================================================" << std::endl;
        }
        if(current_state.get_counter() == 100) {
            bot_actions_receiver::write_to_file(0);
            bot_actions_receiver::write_to_file(1);
            exit(0);
        }
        current_state.reset_game();
        current_state.create_game(client_state::game_mode::SINGLE);
        // show_screen(gui, war_of_ages::screen::END_GAME, war_of_ages::screen::GAME_SCREEN);
    }
}

void end_game_screen_init(tgui::Gui &gui) {
    auto end_game_screen_group = tgui::Group::create();

    auto result = tgui::Label::create();
    result->getRenderer()->setTextSize(40);
    result->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
    result->getRenderer()->setTextColor(tgui::Color::White);
    end_game_screen_group->add(result, "result_label");

    auto start_button = tgui::Button::create("В главное меню");
    start_button->setTextSize(30);
    start_button->onPress([&gui]() { show_screen(gui, screen::START_SCREEN, screen::END_GAME); });
    end_game_screen_group->add(start_button);

    std::vector<tgui::Widget::Ptr> widgets = {result, start_button};
    place_widgets(widgets);

    gui.add(end_game_screen_group, screen_id.at(screen::END_GAME));
    gui.get(screen_id.at(screen::END_GAME))->setVisible(false);
}
}  // namespace war_of_ages