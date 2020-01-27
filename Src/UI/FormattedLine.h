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
//#include "boost/algorithm/string.hpp"

class FormattedLine {
    std::list<Sp<FormattedWord>> words_;

    Sp<sf::Font> font_;
    sf::Vector2f position_;
    sf::Vector2f size_;
    sf::Vector2f max_size_;

public:
    FormattedLine(const sf::String& string, sf::Vector2f position, const Sp<sf::Font>& font, sf::Vector2f max_size);
    virtual ~FormattedLine() = default;
    void format_line(sf::String string, const Sp<sf::Font> &font);

    void draw_to(const Sp<sf::RenderTarget>& window);

    sf::FloatRect get_rect();
    void move_vertical(float distance);
};


#endif //_FORMATTEDLINE_H_
