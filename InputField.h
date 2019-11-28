//
// Created by christian.heusser on 07.11.2019.
//

#ifndef UNTITLED_INPUTFIELD_H
#define UNTITLED_INPUTFIELD_H
#include "DrawableObject.h"
#include "TextOutput.h"

namespace sd {
    class InputField : public DrawableObject{
        sf::Text* text;
        TextOutput* output_;

    public:
        // TODO(FK): remove Textoutput from Input class?
        InputField(sf::Vector2f position, sf::Vector2f size, sf::Color color, TextOutput* output);
        ~InputField();

        void addText(sf::Uint32 input);
        sf::String getTextAndClear();

        void DrawTo(sf::RenderWindow* window) const override;
        void Handle(sf::Event event) override;

    };
}


#endif //UNTITLED_INPUTFIELD_H
