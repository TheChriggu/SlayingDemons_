//
// Created by christian.heusser on 07.11.2019.
//

#include "FormattedWord.h"
#include <iostream>

FormattedWord::FormattedWord(sf::String _text, bool _isGlitching, sf::Vector2f _position, sf::Font* _font) {


    text = new sf::Text();
    text->setFont(*_font);
    text->setString(_text);
    text->setCharacterSize(24);
    text->setFillColor(sf::Color::Black);
    text->setPosition(_position);

    isGlitching = _isGlitching;

    format();
}

FormattedWord::~FormattedWord() {
    delete text;
}

void FormattedWord::drawTo(sf::RenderTarget* window, sf::RenderTarget* glitchWindow) {
    if(isGlitching)
    {
        glitchWindow->draw(*text);
    }
    else
    {
        window->draw(*text);
    }
}

void FormattedWord::setPosition(sf::Vector2f _position) {
    text->setPosition(_position);
}

void FormattedWord::format() {
    return;
}

sf::FloatRect FormattedWord::getRect() {
    return text->getGlobalBounds();
}

void FormattedWord::MoveVertical(float distance) {
    sf::Vector2f position = text->getPosition();
    position.y += distance;
    text->setPosition(position);
}
