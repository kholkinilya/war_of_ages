#include "../include/sprite_supplier.h"
#include "../../game_logic/include/age.h"
#include "../../game_logic/include/bullet.h"
#include "../../game_logic/include/cannon.h"
#include "../../game_logic/include/unit.h"
#include "../include/game_object_size_constants.h"

namespace war_of_ages {

sf::Sprite sprite_supplier::create_sprite_instance(const std::string &texture_filename,
                                                   int width,
                                                   int height) {
    sf::Texture texture;
    texture.loadFromFile(texture_filename);
    sf::Sprite result(texture);
    result.setScale(1. * width / texture.getSize().x, 1. * height / texture.getSize().y);
    return result;
}

sprite_supplier::sprite_supplier() {
    const static std::unordered_map<age_type, std::string> background_texture_file{
        {age_type::STONE, "../client/resources/game/backgrounds/stone/background.png"}};

    const static std::unordered_map<age_type, std::string> road_texture_file{
        {age_type::STONE, "../client/resources/game/roads/stone/road.png"}};

    const static std::unordered_map<age_type, std::string> tower_texture_file{
        {age_type::STONE, "../client/resources/game/towers/stone/tower.png"}};

    const static std::unordered_map<unit_type, std::string> unit_texture_file{
        {unit_type::PEASANT, "../client/resources/game/units/stone/peasant.png"},
        {unit_type::ARCHER, "../client/resources/game/units/stone/archer.png"},
        {unit_type::CHARIOT, "../client/resources/game/units/stone/chariot.png"}};

    const static std::unordered_map<cannon_type, std::string> cannon_texture_file{
        {cannon_type::STONE_LEVEL_1, "../client/resources/game/cannons/stone/level_1.png"},
        {cannon_type::STONE_LEVEL_2, "../client/resources/game/cannons/stone/level_2.png"},
        {cannon_type::STONE_LEVEL_3, "../client/resources/game/cannons/stone/level_3.png"}};

    const static std::map<std::pair<age_type, int>, std::string> cannon_slots_texture_file{
        {{age_type::STONE, 1}, "../client/resources/game/cannon_slots/stone/level_1.png"},
        {{age_type::STONE, 2}, "../client/resources/game/cannon_slots/stone/level_2.png"},
        {{age_type::STONE, 3}, "../client/resources/game/cannon_slots/stone/level_3.png"}};

    const static std::unordered_map<bullet_type, std::string> bullet_texture_file{
        {bullet_type::STONE_LEVEL_1, "../client/resources/game/bullets/stone/level_1.png"},
        {bullet_type::STONE_LEVEL_2, "../client/resources/game/bullets/stone/level_2.png"},
        {bullet_type::STONE_LEVEL_3, "../client/resources/game/bullets/stone/level_3.png"},
        {bullet_type::STONE_ULT, "../client/resources/game/bullets/stone/ult.png"}};

    for (auto &[a_type, filename] : background_texture_file) {
        background_sprite[a_type] = create_sprite_instance(filename, BACKGROUND_WIDTH, BACKGROUND_HEIGHT);
    }

    for (auto &[a_type, filename] : road_texture_file) {
        road_sprite[a_type] = create_sprite_instance(filename, ROAD_WIDTH, ROAD_HEIGHT);
    }

    for (auto &[a_type, filename] : tower_texture_file) {
        background_sprite[a_type] = create_sprite_instance(filename, TOWER_WIDTH, TOWER_HEIGHT);
    }

    for (auto &[u_type, filename] : unit_texture_file) {
        unit_sprite[u_type] = create_sprite_instance(filename, unit::get_stats(u_type).width_pxls,
                                              unit::get_stats(u_type).height_pxls);
    }

    for (auto &[c_type, filename] : cannon_texture_file) {
        cannon_sprite[c_type] = create_sprite_instance(filename, CANNON_WIDTH, CANNON_HEIGHT);
    }

    for (auto &[cs_type, filename] : cannon_slots_texture_file) {
        cannon_slots_sprite[cs_type] = create_sprite_instance(filename, CANNON_SLOT_WIDTH, CANNON_SLOT_HEIGHT);
    }

    for (auto &[b_type, filename] : bullet_texture_file) {
        // TODO: replace with bullet size, when implemented
        bullet_sprite[b_type] = create_sprite_instance(filename, BULLET_WIDTH, BULLET_HEIGHT);
    }
}

sf::Sprite sprite_supplier::reflect_if_needed(sf::Sprite sprite, sprite_supplier::player_side side) {
    if (side == player_side::LEFT) {
        sprite.setScale(-sprite.getScale().x, sprite.getScale().y);
    }
    return sprite;
}

sprite_supplier *sprite_supplier::get_instance() {
    if (supplier == nullptr) {
        supplier = new sprite_supplier();
    }
    return supplier;
}

sf::Sprite sprite_supplier::get_background_sprite(age_type a_type) {
    return background_sprite[a_type];
}

sf::Sprite sprite_supplier::get_road_sprite(age_type a_type) {
    return road_sprite[a_type];
}

sf::Sprite sprite_supplier::get_tower_sprite(age_type a_type, sprite_supplier::player_side side) {
    return reflect_if_needed(tower_sprite[a_type], side);
}

sf::Sprite sprite_supplier::get_cannon_slot_sprite(std::pair<age_type, int> cs_type,
                                                   sprite_supplier::player_side side) {
    return reflect_if_needed(cannon_slots_sprite[cs_type], side);
}

sf::Sprite sprite_supplier::get_unit_sprite(unit_type u_type, sprite_supplier::player_side side) {
    return reflect_if_needed(unit_sprite[u_type], side);
}

sf::Sprite sprite_supplier::get_cannon_sprite(cannon_type c_type, sprite_supplier::player_side side) {
    return reflect_if_needed(cannon_sprite[c_type], side);
}

sf::Sprite sprite_supplier::get_bullet_sprite(bullet_type b_type) {
    return bullet_sprite[b_type];
}

}  // namespace war_of_ages
