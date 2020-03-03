//
// Created by christian.heusser on 03.03.2020.
//

#ifndef SLAYINGDEMONS_SPLASHSCREENS_H
#define SLAYINGDEMONS_SPLASHSCREENS_H

#include "SFML/Graphics.hpp"
#include "Core/GlobalDefinitions.h"

class SplashScreens {
private:
    sf::Clock* clock;
    sf::Texture team_texture;
    sf::Texture school_texture;
    sf::Sprite school_logo;
    sf::Sprite team_logo;

public:
    SplashScreens();
    ~SplashScreens();
    bool DrawTo(Sp<sf::RenderTarget> window);
};


#endif //SLAYINGDEMONS_SPLASHSCREENS_H
