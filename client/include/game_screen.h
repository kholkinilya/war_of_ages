#ifndef WAR_OF_AGES_GAME_SCREEN_H
#define WAR_OF_AGES_GAME_SCREEN_H

#include <TGUI/Backend/SFML-Graphics.hpp>
#include <TGUI/Widgets/BitmapButton.hpp>
#include <TGUI/Widgets/Group.hpp>

namespace war_of_ages {
enum class possession { UNIT, CANNON };

void game_screen_init(sf::View &v, tgui::Gui &gui);

void setup_button(tgui::BitmapButton::Ptr &button);

void setup_buy_buttons(std::vector<tgui::Group::Ptr> &groups, possession p);
}  // namespace war_of_ages

#endif  // WAR_OF_AGES_GAME_SCREEN_H
