//
// Created by christian.heusser on 19.02.2020.
//

#include "RGBOffsetWeak.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>

sd::RGBOffsetWeak::RGBOffsetWeak(Sp<sf::Shader> glitch_shader) : ShaderProcedure(glitch_shader) {
    //TODO(FK): Replace copy-pasta shit

    if(!shader_->loadFromFile("../Resources/Shaders/mainVertexShader.vert", "../Resources/Shaders/rgb_offset_weak.frag"))
    {
        std::cout << "!!!!could not rgb_offset shader\n";
    }
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    shader_->setUniform("maxOffset", 0.05f);

    clock_ = std::make_shared<sf::Clock>(sf::Clock());
}

void sd::RGBOffsetWeak::process(sf::RenderTarget *window, const sf::Drawable *drawable) const {
    shader_->setUniform("time", clock_->getElapsedTime().asSeconds());

    window->draw(*drawable, shader_.get());
}
