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

    void drawTo(sf::RenderWindow* window);

    sf::FloatRect getRect();
};


#endif //UNTITLED_FORMATTEDLINE_H
