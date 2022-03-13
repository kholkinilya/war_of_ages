#ifndef WAR_OF_AGES_PLAYER_H
#define WAR_OF_AGES_PLAYER_H

#include <deque>
#include <mutex>
#include <vector>
#include "age.h"
#include "bullet.h"
#include "cannon.h"
#include "game_constants.h"
#include "unit.h"

namespace war_of_ages {

struct player {
    void update(std::deque<unit> &enemies, int time);  // need all enemies for ult
    void buy_unit(int unit_level);  // unit_level in [0, NUM_OF_UNITS_IN_AGE), unit_type = NUM_OF_AGES *
                                    // m_age + unit_level ???
    void buy_cannon(int cannon_type, int slot);  // the same remark
    void buy_cannon_slot();
    void sell_cannon(int slot);
    void use_ult();
    void clear_dead_objects();

    // Getters

    [[nodiscard]] enum age_type age() const;
    [[nodiscard]] int exp() const;
    [[nodiscard]] int money() const;
    [[nodiscard]] std::deque<unit> units() const;       // Copy, not by & cause of multithreading
    [[nodiscard]] std::vector<bullet> bullets() const;  // The same remark
    [[nodiscard]] std::vector<cannon> cannons() const;  // The same remark
    [[nodiscard]] std::deque<unit> units_to_train() const;
    [[nodiscard]] bool is_alive() const;

private:
    age_type m_age = age_type::STONE;
    int m_exp = 0;
    int m_money = INITIAL_MONEY;
    int m_last_ult = 0;
    std::deque<unit> m_units = {};
    std::vector<bullet> m_bullets = {};
    std::vector<cannon> m_cannons = {
        cannon{cannon_type::NONE, CANNONS_SLOTS_COORD_X[0], CANNONS_SLOTS_COORD_Y[0]}};
    std::deque<unit> m_units_to_train = {};

    mutable std::mutex m_mutex;
};
}  // namespace war_of_ages

#endif  // WAR_OF_AGES_PLAYER_H