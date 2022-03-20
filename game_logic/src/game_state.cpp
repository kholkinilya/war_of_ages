#include "../include/game_state.h"
#include <memory>
#include <vector>
#include "../include/game_commands.h"
#include "../include/player.h"

namespace war_of_ages {

void game_state::update(const std::vector<std::unique_ptr<game_command>> &p1_commands,
                        const std::vector<std::unique_ptr<game_command>> &p2_commands,
                        float time) {
    p1.update(p2, time - state_time);
    p2.update(p1, time - state_time);
    state_time = time;

    for (auto &command : p1_commands) {
        command->apply(p1);
    }
    for (auto &command : p2_commands) {
        command->apply(p2);
    }

    p1.clear_dead_objects();
    p2.clear_dead_objects();
}

[[nodiscard]] std::pair<player_snapshot, player_snapshot> game_state::snapshot_players() const {
    return {p1.snapshot(), p2.snapshot()};
}

game_state::game_state(float start_time) : state_time(start_time) {
}

game_status game_state::get_game_status() const {
    if (!p1.is_alive()) {
        return game_status::P2_WON;
    }
    if (!p2.is_alive()) {
        return game_status::P1_WON;
    }
    return game_status::PROCESSING;
}

void game_state::return_from_pause(float return_time) noexcept {
    state_time = return_time;
}
void game_state::update(std::vector<std::unique_ptr<game_command>> &&p1_commands,
                        std::vector<std::unique_ptr<game_command>> &&p2_commands,
                        float time) {
    update(p1_commands, p2_commands, time);
}

}  // namespace war_of_ages
