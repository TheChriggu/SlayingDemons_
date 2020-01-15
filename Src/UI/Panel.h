//
// Created by felix on 26.11.19.
//

#ifndef SLAYINGDEMONS_PANEL_H
#define SLAYINGDEMONS_PANEL_H

#include "Core/DrawableObject.h"

namespace sd {
    class Panel : public DrawableObject {
    private:
        sp<sf::Sprite> sprite;
        sp<sf::Texture> texture;

    public:
        Panel(sf::Vector2f position, sf::Vector2f size, sf::Color color);
        Panel(sf::Vector2f position, sf::Vector2f size, const char* texture_path);
        ~Panel() override = default;

        bool Setup() override;

        sf::Vector2f GetPosition() override;
        sf::Vector2f GetSize() override;
        void DrawTo(sp<sf::RenderTarget> window) const override;

        void Handle(sf::Event event) override;
    };
}


#endif //SLAYINGDEMONS_PANEL_H
