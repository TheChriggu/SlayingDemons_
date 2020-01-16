//
// Created by felix on 26.11.19.
//

#ifndef _PANEL_H_
#define _PANEL_H_

#include "Core/DrawableObject.h"

namespace sd {
    class Panel : public DrawableObject {
    private:
        Sp<sf::Sprite> sprite_;
        Sp<sf::Texture> texture_;

    public:
        Panel(sf::Vector2f position, sf::Vector2f size, sf::Color color);
        Panel(sf::Vector2f position, sf::Vector2f size, const char* texture_path);
        ~Panel() override = default;

        bool setup() override;

        sf::Vector2f get_position() override;
        sf::Vector2f get_size() override;
        void draw_to(Sp<sf::RenderTarget> window) const override;

        void handle(sf::Event event) override;
    };
}


#endif //_PANEL_H_
