//
// Created by christian.heusser on 19.02.2020.
//

#include "HorizontalZigZag.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>

sd::HorizontalZigZag::HorizontalZigZag(Sp<sf::Shader> glitch_shader) : ShaderProcedure(glitch_shader) {
    auto* noise = new sf::Texture();
    if(!noise->loadFromFile("../Resources/Sprites/noise.png"))
    {
        std::cout << "could not load noise png\n";
    }

    if(!shader_->loadFromFile("../Resources/Shaders/mainVertexShader.vert", "../Resources/Shaders/horizontal_zigzag.frag"))
    {
        std::cout << "!!!!could not rgb_offset shader\n";
    }

    shader_->setUniform("noiseTex", *noise);
    clock_ = std::make_shared<sf::Clock>(sf::Clock());
}

void sd::HorizontalZigZag::process(sf::RenderTarget *window, const sf::Drawable *drawable) const {
    shader_->setUniform("time", clock_->getElapsedTime().asSeconds());

    window->draw(*drawable, shader_.get());
}
