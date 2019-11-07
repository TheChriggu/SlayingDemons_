//
// Created by christian.heusser on 07.11.2019.
//

#ifndef UNTITLED_FORMATTEDWORD_H
#define UNTITLED_FORMATTEDWORD_H
#include "SFML\Graphics.hpp"

class FormattedWord {
    sf::Text* text;
    bool isGlitching;
    void format();

public:
    FormattedWord(sf::String _text, bool _isGlitching, sf::Vector2f _position);
    ~FormattedWord();

    void drawTo(sf::RenderWindow* window, sf::RenderWindow* glitchWindow);

    void setPosition(sf::Vector2f _position);
    sf::FloatRect getRect();

    void toggleGlitch(){
        isGlitching = !isGlitching;
    }
};


#endif //UNTITLED_FORMATTEDWORD_H
