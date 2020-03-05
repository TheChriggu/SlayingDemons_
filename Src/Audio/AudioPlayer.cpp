//
// Created by CHeus on 03.03.2020.
//

#include <iostream>
#include "AudioPlayer.h"
#include "../ScriptEngine/ScriptEngine.h"

sd::AudioPlayer::AudioPlayer() {
    ScriptEngine::get().register_all ("set_background_music", &AudioPlayer::set_background_music, this);
    ScriptEngine::get().register_all ("trigger_sfx", &AudioPlayer::trigger_sfx, this);

    background_music_ = std::make_shared<sf::Music>();
    sound_ = std::make_shared<sf::Sound>();
    sound_buffer_ = std::make_shared<sf::SoundBuffer>();



    if (!background_music_->openFromFile("../Resources/Audio/fantasy.ogg"))
    {
        std::cout << "could not open background music\n";
    }
    background_music_->setLoop(true);
    background_music_->play();
    current_music_ = "fantasy";
}

void sd::AudioPlayer::set_background_music(std::string music) {
    if(music != current_music_)
    {
        current_music_ = music;
        if (!background_music_->openFromFile("../Resources/Audio/" + music + ".ogg"))
        {
            std::cout << "could not open background music\n";
        }
        background_music_->setLoop(true);
        background_music_->play();
    }
}

void sd::AudioPlayer::trigger_sfx(std::string sfx) {
    sound_buffer_->loadFromFile("../Resources/Audio/" + sfx + ".ogg");
    sound_->setBuffer(*sound_buffer_);
    sound_->play();
}
