//
// Created by christian.heusser on 07.11.2019.
//

#ifndef _FORMATTEDLINE_H_
#define _FORMATTEDLINE_H_
//#include "Core/GlobalDefinitions.h"
#include <list>
#include "FormattedWord.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include <strtk.hpp>
#include "Font.h"
#include "Colors.h"
//#include "boost/algorithm/string.hpp"

namespace sd {
    class FormattedLine {

        std::list<Sp<FormattedWord>> words_;

        sf::Vector2f position_;
        sf::Vector2f size_;
        sf::Vector2f max_size_;

    public:
        FormattedLine(std::string string, sf::Vector2f position, sf::Vector2f max_size, Sp<Font> fonts, Sp<Colors> colors);

        virtual ~FormattedLine() = default;

        void format_line(std::string string, Sp<Font> fonts, Sp<Colors> colors);
        std::string get_line();

        void draw_to(const Sp<sf::RenderTarget> &window);

        sf::FloatRect get_rect();

        void move_vertical(float distance);

        void handle(sf::Event event);

        void set_font_size_color(Sp<Font> fonts, int size, Sp<Colors> colors);
        void set_font(Sp<sf::Font> font);
        void set_size(int size);
        void set_color(sf::Color color);

    };
}

#endif //_FORMATTEDLINE_H_
