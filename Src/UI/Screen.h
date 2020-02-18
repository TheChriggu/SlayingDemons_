//
// Created by christian.heusser on 18.02.2020.
//

#ifndef SLAYINGDEMONS_SCREEN_H
#define SLAYINGDEMONS_SCREEN_H

#include "Core/DrawableObject.h"
#include "SFML/Graphics.hpp"

namespace sd {
    class Screen : public DrawableObject{
    private:
        Sp<sf::Sprite> sprite_;
        Sp<sf::RenderTexture> texture_;

    public:
        Screen(sf::Vector2u size);//Sp<sf::RenderTexture> texture);
        ~Screen() override = default;

        void clear();
        void display();
        Sp<sf::RenderTexture> get_texture();

        bool setup() override;

        void draw_to(Sp<sf::RenderTarget> window) const override;

        sf::Vector2f get_position() override;
        sf::Vector2f get_size() override;

        void handle(sf::Event event) override;

    };
}

#endif //SLAYINGDEMONS_SCREEN_H
