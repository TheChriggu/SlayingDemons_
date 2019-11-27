//
// Created by felix on 26.11.19.
//

#ifndef SLAYINGDEMONS_PANEL_H
#define SLAYINGDEMONS_PANEL_H

#include "DrawableObject.h"

namespace sd {
    class Panel : public DrawableObject {
    public:
        Panel(sf::Vector2f position, sf::Vector2f size, sf::Color color);
        Panel(sf::Vector2f position, sf::Vector2f size, sf::Texture texture);
        virtual ~Panel() override = default;

        void Handle(sf::Event event) override;
    };
}


#endif //SLAYINGDEMONS_PANEL_H
