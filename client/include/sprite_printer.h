#ifndef WAR_OF_AGES_SPRITE_PRINTER_H
#define WAR_OF_AGES_SPRITE_PRINTER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include "../../game_logic/include/game_state.h"
#include "sprite_supplier.h"

namespace war_of_ages {
struct sprite_printer {
public:
    sprite_printer();
    void print(tgui::Gui &gui, sf::RenderWindow *window, const std::shared_ptr<game_state> &state);
    void update(float delta);

private:
    sf::Sprite background;
    static void print_units(sf::RenderWindow *window,
                            const std::deque<unit> &units,
                            sprite_supplier::player_side side);
    static void print_bullets(sf::RenderWindow *window,
                              const std::vector<bullet> &bullets,
                              sprite_supplier::player_side side);
};
}  // namespace war_of_ages

#endif  // WAR_OF_AGES_SPRITE_PRINTER_H
