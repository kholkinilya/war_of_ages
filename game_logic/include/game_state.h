#ifndef WAR_OF_AGES_GAME_STATE_H
#define WAR_OF_AGES_GAME_STATE_H

#include <memory>
#include <vector>
#include "game_commands.h"
#include "player.h"

namespace war_of_ages {

struct game_state {
private:
    player p1, p2;
    float state_time;

public:
    explicit game_state(float start_time);
    void update(const std::vector<std::unique_ptr<game_command>> &p1_commands,
                const std::vector<std::unique_ptr<game_command>> &p2_commands,
                float dt);
    [[nodiscard]] std::pair<player_snapshot, player_snapshot> snapshot_players() const;
};

}  // namespace war_of_ages

#endif  // WAR_OF_AGES_GAME_STATE_H