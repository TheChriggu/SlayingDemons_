//
// Created by christian.heusser on 07.11.2019.
//

#ifndef UNTITLED_FORMATTEDLINE_H
#define UNTITLED_FORMATTEDLINE_H
#include <list>
#include "FormattedWord.h"
#include <iostream>
#include "SFML/Graphics.hpp"

class FormattedLine {
    std::list<FormattedWord*>* words;
    void formatLine(sf::String string);
    sf::Vector2f position;
    sf::Vector2f size;

public:
    FormattedLine(sf::String string, sf::Vector2f _position);
    ~FormattedLine();

    void drawTo(sf::RenderTarget* window, sf::RenderTarget* glitchWindow);

    sf::FloatRect getRect();
    void MoveVertical(float distance);

    void toggleGlitch();
};


#endif //UNTITLED_FORMATTEDLINE_H
