//
// Created by christian.heusser on 07.11.2019.
//

#include "FormattedWord.h"

FormattedWord::FormattedWord(const std::string& text, sf::Vector2f position, sd::Format& format) {
    
    text_ = std::make_shared<sf::Text>();
    text_->setString(text);
    text_->setPosition(position);
    
    if(is_bb())
        {
            apply_bb_to_format (format);
        }
    else
        {
            apply_format_to_text (format);
        }
}

void FormattedWord::draw_to(const Sp<sf::RenderTarget>& window) {

    if(!is_bb ())
    {
        window->draw(*text_);
    }
}

void FormattedWord::set_position(sf::Vector2f position) {
    text_->setPosition(position);
}

sf::FloatRect FormattedWord::get_rect() {
    return text_->getGlobalBounds();
}

void FormattedWord::move_vertical(float distance) {
    sf::Vector2f position = text_->getPosition();
    position.y += distance;
    text_->setPosition(position);
}

bool FormattedWord::is_bb ()
{
    return text_->getString ()[0] == '[';
}

void FormattedWord::apply_format_to_text (sd::Format format)
{
    text_->setFont(*(format.font_));
    text_->setCharacterSize(format.size_);
    text_->setFillColor(format.color_);
    text_->setStyle (format.style_);
    
    if(format.is_button_)
        {
            //TODO: create button
        }

}
void FormattedWord::apply_bb_to_format (sd::Format &format)
{
    sf::String code = text_->getString ();

    if(code == "[b]")
        {
            format.style_ = format.style_ | sf::Text::Style::Bold;
        }
    if(code == "[/b]")
        {
            format.style_ = format.style_ & ~(sf::Text::Style::Bold);
        }
}
