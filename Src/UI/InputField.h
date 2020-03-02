//
// Created by christian.heusser on 07.11.2019.
//

#ifndef _INPUTFIELD_H_
#define _INPUTFIELD_H_

#include "Core/DrawableObject.h"
#include "TextOutput.h"
#include "InputTextProcessor.h"
#include "PossibleWords.h"
#include <regex>

#define UNI_ENTER 13
#define UNI_BACKSPACE 8
#define UNI_SPACE 32
#define UNI_TAB 9

namespace sd {
    class InputField : public DrawableObject, public Subscriber {
        Sp<sf::Text> text_;
        Sp<InputTextProcessor> text_processor_;
        
        Sp<PossibleWords> possible_words_;

    public:
        InputField(sf::Vector2f position, sf::Vector2f size, sf::Color color);
        ~InputField() override = default;

        bool setup() override;

        void add_text(sf::Uint32 input);

        sf::Vector2f get_position() override;
        sf::Vector2f get_size() override;

        void draw_to(Sp<sf::RenderTarget> window) const override;
        void handle(sf::Event event) override;
    };
}


#endif //_INPUTFIELD_H_
