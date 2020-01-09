//
// Created by christian.heusser on 07.11.2019.
//

#ifndef UNTITLED_FORMATTEDLINE_H
#define UNTITLED_FORMATTEDLINE_H
#include <list>
#include "FormattedWord.h"
#include <iostream>
#include "SFML/Graphics.hpp"
//#include "boost/algorithm/string.hpp"

class FormattedLine {
    std::list<FormattedWord*>* words;

    sf::Vector2f position;
    sf::Vector2f size;
    sf::Vector2f maxSize;

public:
    FormattedLine(sf::String string, sf::Vector2f _position, sf::Font* _font, sf::Vector2f _maxSize);
    ~FormattedLine();
    void FormatLine(sf::String string, sf::Font* _font);

    void drawTo(sf::RenderTarget* window, sf::RenderTarget* glitchWindow);

    sf::FloatRect getRect();
    void MoveVertical(float distance);

    void toggleGlitch();
};


#endif //UNTITLED_FORMATTEDLINE_H
