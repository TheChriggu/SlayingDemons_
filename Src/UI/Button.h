//
// Created by christian.heusser on 05.11.2019.
//

#ifndef UNTITLED_BUTTON_H
#define UNTITLED_BUTTON_H

#include <functional>
#include "SFML/Graphics.hpp"
#include "Core/DrawableObject.h"
#include "Core/GlobalDefinitions.h"

namespace sd {
    class Button : public DrawableObject {

        sp<sf::Sprite> button;
        sp<sf::Texture> normalTexture;
        sp<sf::Texture> pressedTexture;

        std::function<void()> callback;


    public:
        Button(sf::Vector2f position, sf::Vector2f scale, std::function<void()> _callback);
        ~Button() override = default;

        void down();
        void up();

        void DrawTo(sp<sf::RenderTarget> window) const override;
        bool isPositionOnButton(sf::Vector2f positionToCheck);

        void Handle(sf::Event event) override;
    };
}


#endif //UNTITLED_BUTTON_H
