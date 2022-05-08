#include "../include/random_matchmaker.h"
#include <algorithm>
#include "../include/game_handler.h"

namespace war_of_ages::server {
random_matchmaker &random_matchmaker::instance() {
    static random_matchmaker inst;
    return inst;
}

bool random_matchmaker::user_exists(const std::string &handle) const noexcept {
    return std::find(m_users.begin(), m_users.end(), handle) != m_users.end();
}

bool random_matchmaker::add_user(std::string handle) {
    if (user_exists(handle)) {
        return false;
    }
    m_users.push_back(std::move(handle));
    if (m_users.size() == 2) {
        game_handler::instance().add_game(
            std::move(m_users[0]), std::move(m_users[1]),
            [](const std::string &handle_winner, const std::string &handler_loser) { /* DO NOTHING */ });
        m_users.clear();
    }
    return true;
}

bool random_matchmaker::remove_user(const std::string &handle) {
    if (!user_exists(handle)) {
        return false;
    }
    m_users.erase(std::remove(m_users.begin(), m_users.end(), handle), m_users.end());
    return true;
}

}  // namespace war_of_ages::server