//
// Created by christian.heusser on 03.03.2020.
//

#include "SplashScreens.h"

SplashScreens::SplashScreens() {
    //sf::Texture team_texture;
    team_texture.loadFromFile("../Resources/Sprites/StartUp/team_logo.png");

    //sf::Texture school_texture;
    school_texture.loadFromFile("../Resources/Sprites/StartUp/school_logo.png");

    team_logo.setTexture(team_texture);
    school_logo.setTexture(school_texture);

    clock = new sf::Clock();
}

SplashScreens::~SplashScreens() {
    delete(clock);
}

bool SplashScreens::DrawTo(Sp<sf::RenderTarget> window) {
    if(clock->getElapsedTime().asSeconds () < 5)
    {
        window->draw(team_logo);
        return true;
    }
    else if(clock->getElapsedTime().asSeconds () < 10)
    {
        window->draw(school_logo);
        return true;
    }

    return false;
}


