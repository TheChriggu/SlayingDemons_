//
// Created by christian.heusser on 05.11.2019.
//

#ifndef UNTITLED_BUTTON_H
#define UNTITLED_BUTTON_H

#include <functional>
#include "SFML\Graphics.hpp"

class Button {

    sf::Sprite* button;
    sf::Texture* normalTexture;
    sf::Texture* pressedTexture;

    std::function<void()> callback;


public:
    Button(sf::Vector2f position, sf::Vector2f scale, std::function<void()> _callback);
    ~Button();

    void down();
    void up();

    void drawTo(sf::RenderWindow* window);
    bool isPositionOnButton(sf::Vector2f positionToCheck);
};


#endif //UNTITLED_BUTTON_H
