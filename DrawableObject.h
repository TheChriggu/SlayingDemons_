//
// Created by christian.heusser on 06.11.2019.
//

#ifndef UNTITLED_DISPLAYAREA_H
#define UNTITLED_DISPLAYAREA_H
#include "SFML/Graphics.hpp"
#include "Drawable.h"

namespace sd {
    class DrawableObject : public Drawable {
    protected:
        sf::Sprite* sprite;

    public:
        DrawableObject(sf::Vector2f position, sf::Vector2f size);
        virtual ~DrawableObject();

        void Draw(sf::RenderWindow *window) const override;
    };
}


#endif //UNTITLED_DISPLAYAREA_H
