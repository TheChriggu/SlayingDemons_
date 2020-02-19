//
// Created by christian.heusser on 07.11.2019.
//

#include "FormattedWord.h"

sd::FormattedWord::FormattedWord(std::string text, sf::Vector2f position, sd::Format& format, Sp<Font> fonts) {
    
    text_ = std::make_shared<sf::Text> ();
    text_->setPosition (position);
    

    //apply prerunning bb-codes
    while (text.size() > 0 && text.at (0) == '[')
        {
            std::string code = std::string (text, 0, text.find_first_of (']') + 1);
            text.erase (0, code.size ());
            apply_bb_to_format (code, format, fonts);
        }
    
    //set the actual word
    std::string word = std::string (text, 0, text.find_first_of ('['));
    text.erase (0, word.size ());
    
    if(word != " ")
        {
            text_->setString (sf::String(word));
            apply_format_to_text (format);
        }
        
    //apply trailing bb-codes
    while (text.size () > 0 && text.at (0) == '[')
        {
            std::string code = std::string (text, 0, text.find_first_of (']') + 1);
            text.erase (0, code.size ());
            apply_bb_to_format (code, format, fonts);
        }
        
    //add trailing spaces or punctuation if not included in word
    if(text.size() > 0 && word.size() > 0)
        {
            text_->setString (text_->getString() + sf::String(text));
        }
}

void sd::FormattedWord::draw_to(const Sp<sf::RenderTarget>& window) {

    if(!is_bb ())
    {
        window->draw(*text_);
    }
}

void sd::FormattedWord::set_position(sf::Vector2f position) {
    text_->setPosition(position);
}

sf::FloatRect sd::FormattedWord::get_rect() {
    return text_->getGlobalBounds();
}

void sd::FormattedWord::move_vertical(float distance) {
    sf::Vector2f position = text_->getPosition();
    position.y += distance;
    text_->setPosition(position);
}

bool sd::FormattedWord::is_bb ()
{
    return text_->getString ()[0] == '[';
}

void sd::FormattedWord::apply_format_to_text (sd::Format format)
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
void sd::FormattedWord::apply_bb_to_format (std::string code, sd::Format &format, Sp<Font> fonts)
{
    if(code == "[b]")
        {
            format.style_ = format.style_ | sf::Text::Style::Bold;
        }
    if(code == "[/b]")
        {
            format.style_ = format.style_ & ~(sf::Text::Style::Bold);
        }
    if(code == "[i]")
        {
            format.style_ = format.style_ | sf::Text::Style::Italic;
        }
    if(code == "[/i]")
        {
            format.style_ = format.style_ & ~(sf::Text::Style::Italic);
        }
    if(code.find("[size=") != std::string::npos)
    {
        int size = std::stoi(code.substr(6, code.length()-7));
        format.size_ = size;
    }
    if(code.find("[font=") != std::string::npos)
    {
        format.font_ = fonts->GetFont(code.substr(6, code.length()-7));
    }
    if(code.find("[color=") != std::string::npos)
    {
        std::vector<std::string> values;

        std::string trash;
        int r,g,b,a;
        strtk::parse(code, "=,]", trash, r,g,b,a);

        format.color_ = sf::Color(r,g,b,a);
    }
}
