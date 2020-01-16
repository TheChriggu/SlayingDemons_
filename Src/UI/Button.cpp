//
// Created by christian.heusser on 05.11.2019.
//

#include <iostream>
#include <memory>
#include <utility>
#include "Button.h"
#include "IO/UserInput.h"

// TODO(FK): clean up name
sd::Button::Button(sf::Vector2f position, sf::Vector2f scale, std::function<void()> callback)
    : DrawableObject("button")
{
    button_ = std::make_shared<sf::Sprite>();
    normal_texture_ = std::make_shared<sf::Texture>();
    pressed_texture_ = std::make_shared<sf::Texture>();
    if (!normal_texture_->loadFromFile("../Resources/Sprites/Buttons/blue_button04.png"))
    {
        std::cout << "Could not load ButtonUp!\n";
        return;
    }
    if (!pressed_texture_->loadFromFile("../Resources/Sprites/Buttons/blue_button05.png"))
    {
        std::cout << "Could not load ButtonUp!\n";
        return;
    }
    button_->setTexture(*normal_texture_, false);
    button_->setPosition(position);
    button_->setScale(scale);
    callback_ = std::move(callback);
}

void sd::Button::down() {
    button_->setTexture(*pressed_texture_, true);
}

void sd::Button::up() {
    button_->setTexture(*normal_texture_, true);
    callback_();
}

void sd::Button::draw_to(Sp<sf::RenderTarget> window) const {
    window->draw(*button_.get());
}

bool sd::Button::is_position_on_button(sf::Vector2f position_to_check) {
    sf::Rect bounds = button_->getGlobalBounds();
    return bounds.contains(position_to_check);
}

void sd::Button::handle(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            auto mouse_pos = sd::UserInput::GetInstance ()->get_mouse_position ();

            if(is_position_on_button (mouse_pos))
            {
                down();
            }
        }
    }

    if (event.type == sf::Event::MouseButtonReleased)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            up();
        }
    }
}

