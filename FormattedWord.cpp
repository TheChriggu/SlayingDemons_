//
// Created by christian.heusser on 07.11.2019.
//

#include "FormattedWord.h"
#include <iostream>

FormattedWord::FormattedWord(sf::String _text, bool _isGlitching, sf::Vector2f _position) {
    sf::Font* font = new sf::Font();
    if (!font->loadFromFile("../Resources/Fonts/comic.ttf"))
    {
        std::cout << "Could not load Font!\n";
        return;
    }

    text = new sf::Text();
    text->setFont(*font);
    text->setString(_text);
    text->setCharacterSize(24);
    text->setFillColor(sf::Color::Magenta);
    text->setPosition(_position);

    isGlitching = _isGlitching;

    format();
}

FormattedWord::~FormattedWord() {
    delete text;
}

void FormattedWord::drawTo(sf::RenderWindow* window, sf::RenderWindow* glitchWindow) {
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
