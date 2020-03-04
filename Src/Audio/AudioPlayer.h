//
// Created by CHeus on 03.03.2020.
//

#ifndef SLAYINGDEMONS_AUDIOPLAYER_H
#define SLAYINGDEMONS_AUDIOPLAYER_H

#include "SFML/Audio.hpp"
#include "../Core/GlobalDefinitions.h"

namespace sd {
    class AudioPlayer {
    private:
        Sp<sf::Music> background_music_;
        std::string current_music_;
        Sp<sf::SoundBuffer> sound_buffer_;
        Sp<sf::Sound> sound_;

    public:
        AudioPlayer();

        ~AudioPlayer() = default;

        void set_background_music(std::string music);
        void trigger_sfx(std::string sfx);
    };
}

#endif //SLAYINGDEMONS_AUDIOPLAYER_H
