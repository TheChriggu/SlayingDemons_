//
// Created by CHeus on 03.03.2020.
//

#ifndef SLAYINGDEMONS_AUDIOPLAYER_H
#define SLAYINGDEMONS_AUDIOPLAYER_H

#include "SFML/Audio.hpp"
#include "../Core/GlobalDefinitions.h"

class AudioPlayer {
private:
    Sp<sf::Music> background_music_;

public:
    AudioPlayer();
    ~AudioPlayer() = default;
};


#endif //SLAYINGDEMONS_AUDIOPLAYER_H
