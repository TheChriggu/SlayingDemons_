//
// Created by christian.heusser on 07.11.2019.
//

#ifndef UNTITLED_FORMATTEDWORD_H
#define UNTITLED_FORMATTEDWORD_H

#include <Core/GlobalDefinitions.h>
#include "SFML/Graphics.hpp"

class FormattedWord {

    sp<sf::Text> text;
    sp<sf::Font> font;

public:
    FormattedWord(const sf::String& _text, sf::Vector2f _position, const sp<sf::Font>& _font);
    virtual ~FormattedWord() = default;

    void drawTo(const sp<sf::RenderTarget>& window);

    void setPosition(sf::Vector2f _position);
    sf::FloatRect getRect();
    void MoveVertical(float distance);

private:

    void format();
};


#endif //UNTITLED_FORMATTEDWORD_H
