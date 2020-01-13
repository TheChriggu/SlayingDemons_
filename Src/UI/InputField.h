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
        sp<sf::Text> text;
        sp<InputTextProcessor> textProcessor;

    public:
        InputField(sf::Vector2f position, sf::Vector2f size, sf::Color color);
        ~InputField() override;

        bool Setup() override;

        void addText(sf::Uint32 input);

        void DrawTo(sf::RenderTarget* window) const override;
        void Handle(sf::Event event) override;
    };
}


#endif //UNTITLED_INPUTFIELD_H
