#include "../../include/screens/wait_screen.h"
#include "../../include/screen_handler.h"
#include "../../include/ui_functions.h"

// TGUI widgets
#include <TGUI/Widgets/Button.hpp>
#include <TGUI/Widgets/Group.hpp>
#include <TGUI/Widgets/Picture.hpp>

namespace war_of_ages {

void opponent_waiting_screen_init(tgui::Gui &gui) {
    auto opponent_waiting_screen_group = tgui::Group::create();
    auto loading = tgui::Picture::create("../client/resources/pictures/loading.png");
    opponent_waiting_screen_group->add(loading, "image");

    auto return_button = tgui::Button::create("В главное меню");
    return_button->setTextSize(30);
    return_button->onPress(
        [&gui]() { screen_handler::instance().change_screen(screen_handler::screen_type::START_SCREEN); });
    opponent_waiting_screen_group->add(return_button);

    std::vector<tgui::Widget::Ptr> widgets = {loading, return_button};
    place_widgets(widgets);
    gui.add(opponent_waiting_screen_group,
            screen_handler::screen_id.at(screen_handler::screen_type::WAIT_OPPONENT));
    gui.get(screen_handler::screen_id.at(screen_handler::screen_type::WAIT_OPPONENT))->setVisible(false);
}

}  // namespace war_of_ages