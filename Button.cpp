//
// Created by christian.heusser on 05.11.2019.
//

#include <iostream>
#include "Button.h"


Button::Button(sf::Vector2f position, sf::Vector2f scale, std::function<void()> _callback) {
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

Button::~Button() {
    delete normalTexture;
    delete pressedTexture;
    delete button;
    button = 0;
}

void Button::down() {
    button->setTexture(*pressedTexture, true);
}

void Button::up() {
    button->setTexture(*normalTexture, true);
    callback();
}

void Button::drawTo(sf::RenderWindow *window) {
    window->draw(*button);
}

bool Button::isPositionOnButton(sf::Vector2f positionToCheck) {
    sf::Rect bounds = button->getGlobalBounds();
    return bounds.contains(positionToCheck);
}

