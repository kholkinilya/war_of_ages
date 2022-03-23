#ifndef WAR_OF_AGES_TOURNAMENT_H
#define WAR_OF_AGES_TOURNAMENT_H

#include <TGUI/Widgets/Grid.hpp>  // tgui::Gui, tgui::Grid
#include <map>
#include <mutex>
#include <vector>
#include <string>

namespace war_of_ages {

struct tournament {
private:
    enum class result { NONE, VICTORY, DEFEAT };
    static inline const int WIN_POINTS = 1;
    int part_number = 0;
    std::vector<std::string> participants;
    std::map<std::string, int> id;
    std::vector<std::vector<result>> match_results;
    std::vector<int> sum;
    std::vector<int> place;
    std::mutex m;
    bool is_grid_updated = true;

    void update_places_lock_held();

public:
    void add_participant(const std::string &handle);

    void add_result(const std::string &winner, const std::string &loser);

    void remove_participant(const std::string &handle);

    void update_grid(const tgui::Grid::Ptr &grid);
};

}  // namespace war_of_ages

#endif  // WAR_OF_AGES_TOURNAMENT_H
