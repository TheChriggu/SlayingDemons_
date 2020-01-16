//
// Created by christian.heusser on 05.11.2019.
//

#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <functional>
#include "SFML/Graphics.hpp"
#include "Core/DrawableObject.h"
#include "Core/GlobalDefinitions.h"

namespace sd {
    class Button : public DrawableObject {

        Sp<sf::Sprite> button_;
        Sp<sf::Texture> normal_texture_;
        Sp<sf::Texture> pressed_texture_;

        std::function<void()> callback_;


    public:
        Button(sf::Vector2f position, sf::Vector2f scale, std::function<void()> callback);
        ~Button() override = default;

        void down();
        void up();

        void draw_to(Sp<sf::RenderTarget> window) const override;
        bool is_position_on_button(sf::Vector2f position_to_check);

        void handle(sf::Event event) override;
    };
}


#endif //_BUTTON_H_
