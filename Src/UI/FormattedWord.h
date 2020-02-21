//
// Created by christian.heusser on 07.11.2019.
//

#ifndef _FORMATTEDWORD_H_
#define _FORMATTEDWORD_H_

#include <Core/GlobalDefinitions.h>
#include "SFML/Graphics.hpp"
#include "Format.h"
#include <strtk.hpp>
#include "Font.h"

namespace sd {
    class FormattedWord {

        Sp<sf::Text> text_;
        std::string on_click_text_;

    public:
        FormattedWord(std::string text, sf::Vector2f position, sd::Format &format, Sp<Font> fonts);

        virtual ~FormattedWord() = default;

        void draw_to(const Sp<sf::RenderTarget> &window);

        void set_position(sf::Vector2f position);

        sf::FloatRect get_rect();

        void move_vertical(float distance);

        void handle(sf::Event event);

    private:
        void apply_format_to_text(sd::Format format);

        void apply_bb_to_format(std::string code, sd::Format &format, Sp<Font> fonts);

        bool is_bb();

        bool is_position_on_word(sf::Vector2f position_to_check);
    };
}

#endif //_FORMATTEDWORD_H_
