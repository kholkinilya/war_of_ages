#ifndef WAR_OF_AGES_CLIENT_H
#define WAR_OF_AGES_CLIENT_H

#include <SFML/Graphics.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <memory>
#include "screen_defines.h"
#include "tournament.h"

namespace war_of_ages {

// Will be implemented to the end by Timur

struct client_state {
private:
    tgui::String handle;

    screen cur_screen;

    std::shared_ptr<tournament> cur_tournament;

public:
    explicit client_state(tgui::String handle_, screen cur_screen_);
    [[nodiscard]] tgui::String get_handle() const;

    [[nodiscard]] tgui::String get_cur_screen_id() const;
    [[nodiscard]] screen get_cur_screen() const;

    [[nodiscard]] std::shared_ptr<tournament> get_cur_tournament() const;
};

}  // namespace war_of_ages

#endif  // WAR_OF_AGES_CLIENT_H
