//
// Created by christian.heusser on 03.03.2020.
//

#include <iostream>
#include "SplashScreens.h"

SplashScreens::SplashScreens() {
    //sf::Texture team_texture;
    team_texture_.loadFromFile("../Resources/Sprites/StartUp/team_logo.png");

    //sf::Texture school_texture;
    school_texture_.loadFromFile("../Resources/Sprites/StartUp/school_logo.png");

    team_logo_.setTexture(team_texture_);
    school_logo_.setTexture(school_texture_);

    clock_ = new sf::Clock();

    if(!shader_.loadFromFile("../Resources/Shaders/mainVertexShader.vert", "../Resources/Shaders/fade_in_and_out.frag"))
    {
        std::cout << "!!!!could not load fade_in_and_out_shader shader\n";
    }
}

SplashScreens::~SplashScreens() {
    delete(clock_);
}

bool SplashScreens::DrawTo(Sp<sf::RenderTarget> window) {
    shader_.setUniform("time", clock_->getElapsedTime().asSeconds());

    if(clock_->getElapsedTime().asSeconds () < 5)
    {
        window->draw(team_logo_, &shader_);
        return true;
    }
    else if(clock_->getElapsedTime().asSeconds () < 10)
    {
        window->draw(school_logo_, &shader_);
        return true;
    }

    return false;
}


