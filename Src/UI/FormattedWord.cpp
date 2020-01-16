//
// Created by christian.heusser on 07.11.2019.
//

#include "FormattedWord.h"

FormattedWord::FormattedWord(const sf::String& _text, sf::Vector2f _position, const sp<sf::Font>& _font) {
    font = _font;

    text = std::make_shared<sf::Text>();
    text->setFont(*_font);
    text->setString(_text);
    text->setCharacterSize(24);
    text->setFillColor(sf::Color::Black);
    text->setPosition(_position);

    format();
}

void FormattedWord::drawTo(const sp<sf::RenderTarget>& window) {

    window->draw(*text);
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
