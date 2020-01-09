//
// Created by felix on 09.01.20.
//

#include "WeakGlitch.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include <utility>
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>

sd::WeakGlitch::WeakGlitch(sf::Shader* glitchShader)
    : ShaderProcedure(glitchShader)
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

void sd::WeakGlitch::Process(sf::RenderTarget *window, const sf::Sprite* drawable) const {
    shader_->setUniform("time", clock_->getElapsedTime().asSeconds());
    std::cout << "Test2" << std::endl;

    sf::Sprite* sprite = new sf::Sprite();
    sf::Texture* noise = new sf::Texture();
    if(!noise->loadFromFile("../Resources/Sprites/noise.png"))
    {
        std::cout << "could not load noise png\n";
    }

    sprite->setTexture(*noise);
    //window->draw(*sprite, shader_);
    window->draw(*drawable, shader_);
}
