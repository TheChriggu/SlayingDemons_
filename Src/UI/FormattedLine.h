//
// Created by christian.heusser on 07.11.2019.
//

#ifndef UNTITLED_FORMATTEDLINE_H
#define UNTITLED_FORMATTEDLINE_H
#include "Core/GlobalDefinitions.h"
#include <list>
#include "FormattedWord.h"
#include <iostream>
#include "SFML/Graphics.hpp"
//#include "boost/algorithm/string.hpp"

class FormattedLine {
    std::list<sp<FormattedWord>> words;

    sp<sf::Font> font;
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Vector2f maxSize;

public:
    FormattedLine(const sf::String& string, sf::Vector2f _position, const sp<sf::Font>& _font, sf::Vector2f _maxSize);
    virtual ~FormattedLine() = default;
    void FormatLine(sf::String string, const sp<sf::Font>& _font);

    void drawTo(const sp<sf::RenderTarget>& window);

    sf::FloatRect getRect();
    void MoveVertical(float distance);
};


#endif //UNTITLED_FORMATTEDLINE_H
