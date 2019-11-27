//
// Created by christian.heusser on 05.11.2019.
//

#include <iostream>
#include "Button.h"


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

