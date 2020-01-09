//
// Created by felix on 09.01.20.
//

#include "Glitch.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include <utility>
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>

sd::Glitch::Glitch(sp<sf::Shader> glitchShader)
    : ShaderProcedure(std::move(glitchShader))
{

    // TODO(FK): Replace copy-pasta shit
    sf::Texture* noise = new sf::Texture();
    if(!noise->loadFromFile("../Resources/Sprites/noise.png"))
    {
        std::cout << "could not load noise png\n";
    }

    //shader = new sf::Shader();
    if(!shader_->loadFromFile("../Resources/Shaders/glitch.vert", "../Resources/Shaders/glitch.frag"))
    {
        std::cout << "!!!!could not load shader\n";
    }
    shader_->setUniform("noiseTex", *noise);
    clock_ = std::make_shared<sf::Clock>(sf::Clock());
}

void sd::Glitch::Process(sf::RenderTarget *window, const sf::Drawable *drawable) const {
    shader_->setUniform("time", clock_->getElapsedTime().asSeconds());

    window->draw(*drawable, shader_.get());
}
