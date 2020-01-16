//
// Created by christian.heusser on 07.11.2019.
//

#include "FormattedWord.h"

FormattedWord::FormattedWord(const sf::String& text, sf::Vector2f position, const Sp<sf::Font>& font) {
    font_ = font;

    text_ = std::make_shared<sf::Text>();
    text_->setFont(*font);
    text_->setString(text);
    text_->setCharacterSize(24);
    text_->setFillColor(sf::Color::Black);
    text_->setPosition(position);

    format();
}

void FormattedWord::draw_to(const Sp<sf::RenderTarget>& window) {

    window->draw(*text_);
}

void FormattedWord::set_position(sf::Vector2f position) {
    text_->setPosition(position);
}

void FormattedWord::format() {
    return;
}

sf::FloatRect FormattedWord::get_rect() {
    return text_->getGlobalBounds();
}

void FormattedWord::move_vertical(float distance) {
    sf::Vector2f position = text_->getPosition();
    position.y += distance;
    text_->setPosition(position);
}
