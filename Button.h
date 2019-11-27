//
// Created by christian.heusser on 05.11.2019.
//

#ifndef UNTITLED_BUTTON_H
#define UNTITLED_BUTTON_H

#include <functional>
#include "SFML/Graphics.hpp"
#include "DrawableObject.h"

namespace sd {
    class Button : public DrawableObject {

        sf::Sprite* button;
        sf::Texture* normalTexture;
        sf::Texture* pressedTexture;

        std::function<void()> callback;


    public:
        Button(sf::Vector2f position, sf::Vector2f scale, std::function<void()> _callback);
        ~Button();

        void down();
        void up();

        void Draw(sf::RenderWindow* window) const override;
        bool isPositionOnButton(sf::Vector2f positionToCheck);

        void Handle(sf::Event event) override;
    };
}


#endif //UNTITLED_BUTTON_H
