//
// Created by christian.heusser on 07.11.2019.
//

#ifndef _FORMATTEDWORD_H_
#define _FORMATTEDWORD_H_

#include <Core/GlobalDefinitions.h>
#include "SFML/Graphics.hpp"

class FormattedWord {

    Sp<sf::Text> text_;
    Sp<sf::Font> font_;

public:
    FormattedWord(const sf::String& text, sf::Vector2f position, const Sp<sf::Font>& font);
    virtual ~FormattedWord() = default;

    void draw_to(const Sp<sf::RenderTarget>& window);

    void set_position(sf::Vector2f position);
    sf::FloatRect get_rect();
    void move_vertical(float distance);

private:

    void format();
};


#endif //_FORMATTEDWORD_H_
