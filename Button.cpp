//
// Created by christian.heusser on 05.11.2019.
//

#include <iostream>
#include "Button.h"
#include "UserInput.h"


sd::Button::Button(sf::Vector2f position, sf::Vector2f scale, std::function<void()> _callback)
    : DrawableObject(position, scale)
{
    button = new sf::Sprite();;
    normalTexture = new sf::Texture();
    pressedTexture = new sf::Texture();
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
    callback = _callback;
}

sd::Button::~Button() {
    delete normalTexture;
    delete pressedTexture;
    delete button;
    button = 0;
}

void sd::Button::down() {
    button->setTexture(*pressedTexture, true);
}

void sd::Button::up() {
    button->setTexture(*normalTexture, true);
    callback();
}

void sd::Button::Draw(sf::RenderWindow *window) const {
    window->draw(*button);
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
            std::cout << "after mouse pos" << std::endl;
            sf::Vector2f test;
            test.x = mousePos.x;
            test.y = mousePos.y;
            if(isPositionOnButton(test))
            {
                std::cout << "down" << std::endl;
                down();
            }
        }
    }

    if (event.type == sf::Event::MouseButtonReleased)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            std::cout << "up" << std::endl;
            up();
        }
    }
}

