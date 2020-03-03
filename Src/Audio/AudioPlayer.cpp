//
// Created by CHeus on 03.03.2020.
//

#include <iostream>
#include "AudioPlayer.h"

AudioPlayer::AudioPlayer() {
    background_music_ = std::make_shared<sf::Music>();
    if (!background_music_->openFromFile("../Resources/Audio/fantasy.ogg"))
    {
        std::cout << "could not open background music\n";
    }
    background_music_->setLoop(true);
    background_music_->play();
}
