#ifndef WAR_OF_AGES_GAME_OBJECT_SIZE_CONSTANTS_H
#define WAR_OF_AGES_GAME_OBJECT_SIZE_CONSTANTS_H

#include "../../game_logic/include/game_constants.h"

namespace war_of_ages {

// TODO: Timur will make those constants decent (they are almost random now)

constexpr int BACKGROUND_WIDTH = 1920;
constexpr int BACKGROUND_HEIGHT = 1080;

constexpr int ROAD_WIDTH = 2500;
constexpr int ROAD_HEIGHT = 500;

constexpr int TOWER_WIDTH = 450;
constexpr int TOWER_HEIGHT = 350;

constexpr int CANNON_SLOT_WIDTH = 70;
constexpr int CANNON_SLOT_HEIGHT = 70;

constexpr int CANNON_WIDTH = 70;
constexpr int CANNON_HEIGHT = 70;

constexpr int DELTA = 50;

constexpr int BUTTON_WIDTH = 70;
constexpr int BUTTON_HEIGHT = 70;
constexpr int BUTTON_Y = 50;
constexpr int DELTA_X = 96;

constexpr int HP_HEIGHT = 20;

constexpr int FPS_LABEL_HEIGHT = 20;

constexpr int COIN_WIDTH = 50;
constexpr int COIN_HEIGHT = 50;
constexpr int COST_WIDTH = 30;
constexpr int COST_HEIGHT = 30;

constexpr int BATTLE_DELTA = 20;

constexpr float NORMALIZE = (ROAD_WIDTH - 2 * (TOWER_WIDTH - 2 * DELTA)) / FIELD_LENGTH_PXLS;

constexpr float CANNON_COEF = 0.775;

}  // namespace war_of_ages

#endif  // WAR_OF_AGES_GAME_OBJECT_SIZE_CONSTANTS_H
