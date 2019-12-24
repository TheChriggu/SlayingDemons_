//
// Created by christian.heusser on 07.11.2019.
//

#ifndef UNTITLED_INPUTFIELD_H
#define UNTITLED_INPUTFIELD_H
#include "Core/DrawableObject.h"
#include "TextOutput.h"
#include "InputTextProcessor.h"

namespace sd {
    class InputField : public DrawableObject{
        sf::Text* text;
        TextOutput* output_;
        InputTextProcessor* textProcessor;

    public:
        // TODO(FK): remove Textoutput from Input class?
        InputField(sf::Vector2f position, sf::Vector2f size, sf::Color color, TextOutput* output, Room* room);
        ~InputField();

        void addText(sf::Uint32 input);

        void DrawTo(sf::RenderTarget* window) const override;
        void Handle(sf::Event event) override;

    };
}


#endif //UNTITLED_INPUTFIELD_H
