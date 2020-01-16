//
// Created by christian.heusser on 05.11.2019.
//

#include <iostream>
#include <memory>
#include <utility>
#include "Button.h"
#include "IO/UserInput.h"

// TODO(FK): clean up name
sd::Button::Button(sf::Vector2f position, sf::Vector2f scale, std::function<void()> _callback)
    : DrawableObject("button")
{
    button = std::make_shared<sf::Sprite>();
    normalTexture = std::make_shared<sf::Texture>();
    pressedTexture = std::make_shared<sf::Texture>();
    if (!normalTexture->loadFromFile("../Resources/Sprites/Buttons/blue_button04.png"))
    {
        std::cout << "Could not load ButtonUp!\n";
        return;
    }
    if (!pressedTexture->loadFromFile("../Resources/Sprites/Buttons/blue_button05.png"))
    {
        std::cout << "Could not load ButtonUp!\n";
        return;
    }
    button->setTexture(*normalTexture, false);
    button->setPosition(position);
    button->setScale(scale);
    callback = std::move(_callback);
}

void sd::Button::down() {
    button->setTexture(*pressedTexture, true);
}

void sd::Button::up() {
    button->setTexture(*normalTexture, true);
    callback();
}

void sd::Button::DrawTo(sp<sf::RenderTarget> window) const {
    window->draw(*button.get());
}

bool sd::Button::isPositionOnButton(sf::Vector2f positionToCheck) {
    sf::Rect bounds = button->getGlobalBounds();
    return bounds.contains(positionToCheck);
}

void sd::Button::Handle(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            auto mousePos = sd::UserInput::GetInstance()->GetMousePosition();

            if(isPositionOnButton(mousePos))
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

