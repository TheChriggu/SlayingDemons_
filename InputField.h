//
// Created by christian.heusser on 07.11.2019.
//

#ifndef UNTITLED_INPUTFIELD_H
#define UNTITLED_INPUTFIELD_H
#include "DrawableObject.h"

namespace sd {
    class InputField : public DrawableObject{
        sf::Text* text;

    public:
        InputField(sf::Vector2f position, sf::Vector2f size, sf::Color color);
        ~InputField();

        void addText(sf::Uint32 input);
        sf::String getTextAndClear();

        void Draw(sf::RenderWindow* window) const override;
    };
}


#endif //UNTITLED_INPUTFIELD_H
