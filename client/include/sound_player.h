#ifndef WAR_OF_AGES_SOUND_PLAYER_H
#define WAR_OF_AGES_SOUND_PLAYER_H

#include <SFML/Audio/Music.hpp>
namespace war_of_ages {

struct sound_player {
    enum class sound_type {
        BATTLE,
        LOBBY,
        ENUM_END
    };

public:
    sound_player();
    void change(sound_type from, sound_type to);
    void play(sound_type type);
    void set_volume(sound_type to, float new_volume);
    float get_volume(sound_type to);
    sf::SoundSource::Status status(sound_type type);

private:
    std::unordered_map<sound_type, sf::Music> sounds;
    std::string to_string(sound_type type);
};

}

#endif  // WAR_OF_AGES_SOUND_PLAYER_H
