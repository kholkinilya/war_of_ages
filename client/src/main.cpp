#include <SFML/Graphics.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include "../include/tournament_screens.h"
namespace war_of_ages {

void screens_init(tgui::Gui& gui) {
    // Widgets of every screen are defined here

    // Ilya's screens

    tournament_screen_init(gui);
    tournament_creation_screen_init(gui);
    tournament_join_screen_init(gui);

    // end Ilya's screens
}

}

int main() {
    sf::RenderWindow window{sf::VideoMode::getFullscreenModes()[0], "War of Ages", sf::Style::Fullscreen};
    tgui::Gui gui(window);

    war_of_ages::screens_init(gui);

    gui.get("tournament_join_screen_group")->setVisible(true); // TODO: replace with main screen when implemented

    sf::Texture t;
    t.loadFromFile("../client/resources/pictures/fullHD_kittens.jpg");
    sf::Sprite s;
    s.setTexture(t);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            gui.handleEvent(event);

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(s);

        gui.draw();

        window.display();
    }
}