//
// Created by christian.heusser on 06.11.2019.
//

#ifndef UNTITLED_DISPLAYAREA_H
#define UNTITLED_DISPLAYAREA_H
#include "SFML/Graphics.hpp"
#include "Drawable.h"

namespace sd {
    class DrawableObject : public Drawable {

    public:
        DrawableObject();
        virtual ~DrawableObject();

        void DrawTo(sf::RenderWindow *window) const = 0;

        virtual sf::Vector2f GetPosition();
        virtual sf::Vector2f GetSize();

        virtual void Handle(sf::Event event) = 0;
    };
}


#endif //UNTITLED_DISPLAYAREA_H
