//
// Created by christian.heusser on 03.03.2020.
//

#ifndef SLAYINGDEMONS_SPLASHSCREENS_H
#define SLAYINGDEMONS_SPLASHSCREENS_H

#include "SFML/Graphics.hpp"
#include "Core/GlobalDefinitions.h"

class SplashScreens {
private:
    sf::Clock* clock_;
    sf::Texture team_texture_;
    sf::Texture school_texture_;
    sf::Sprite school_logo_;
    sf::Sprite team_logo_;
    sf::Shader shader_;

public:
    SplashScreens();
    ~SplashScreens();
    bool DrawTo(Sp<sf::RenderTarget> window);
};


#endif //SLAYINGDEMONS_SPLASHSCREENS_H
