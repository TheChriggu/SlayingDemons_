//
// Created by christian.heusser on 06.11.2019.
//

#ifndef UNTITLED_TEXTGLITCH_H
#define UNTITLED_TEXTGLITCH_H
#include "SFML\Graphics.hpp"


class TextGlitch {
    sf::RenderWindow* window;

public:
    TextGlitch();
    ~TextGlitch();

    sf::Texture* glitch(sf::Text* text);
};


#endif //UNTITLED_TEXTGLITCH_H
