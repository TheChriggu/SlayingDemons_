//
// Created by christian.heusser on 07.11.2019.
//

#include "FormattedLine.h"
#include <memory>


FormattedLine::FormattedLine(const sf::String& string, sf::Vector2f position, const Sp<sf::Font>& font, sf::Vector2f max_size) {
    sd::Format format;
    format.style_ = sf::Text::Italic;
    format.size_ = 25;
    format.is_button_ = false;
    format.color_ = sf::Color::Red;
    format.font_ = font_;
    
    font_ = font;
    position_ = position;
    max_size_ = max_size;
    words_.push_back(std::make_shared<FormattedWord>("", position, format));
  format_line (string, font);

}

void FormattedLine::draw_to(const Sp<sf::RenderTarget>& window) {
    for (const auto& word : words_) {
        word->draw_to (window);
    }
}

void FormattedLine::format_line(sf::String string, const Sp<sf::Font> &font) {
    /*std::vector<std::string> splitVec;
    std::string delims = " []";
    boost::split(splitVec, string, boost::algorithm::is_any_of(delims));*/
    
    sd::Format format;
    format.style_ = sf::Text::Regular;
    format.size_ = 25;
    format.is_button_ = false;
    format.color_ = sf::Color::Black;
    format.font_ = font_;
    
    sf::Vector2f next_position =  sf::Vector2f(get_rect ().left, get_rect ().top + get_rect ().height);
    
    std::vector<std::string> string_vector;
    strtk::parse(string, " ", string_vector, strtk::split_options::default_mode);
    
    for(auto word : string_vector)
        {
            
            Sp<FormattedWord> newWord = std::make_shared<FormattedWord>(FormattedWord(word, next_position, format));
            next_position.x += newWord->get_rect ().width;
            if(next_position.x > max_size_.x)
                {
                    next_position = sf::Vector2f(get_rect ().left, get_rect ().top + get_rect ().height);
                    newWord->set_position (next_position);
                    next_position.x += newWord->get_rect ().width;
                }
        
            words_.push_back(newWord);
        }
}

sf::FloatRect FormattedLine::get_rect(){
    sf::FloatRect ret_val = words_.front ()->get_rect ();

    for (const auto& word : words_)
    {
        sf::FloatRect rect = word->get_rect ();
        if (rect.top < ret_val.top)
        {
            ret_val.top = rect.top;
        }
        if (rect.left < ret_val.left)
        {
            ret_val.left = rect.left;
        }
        if (rect.top + rect.height > ret_val.top + ret_val.height)
        {
            ret_val.height = rect.top + rect.height - ret_val.top;
        }
        if (rect.left + rect.width > ret_val.left + ret_val.width)
        {
            ret_val.width = rect.left + rect.width - ret_val.left;
        }
    }
    return ret_val;
}

void FormattedLine::move_vertical(float distance) {
    position_.y += distance;
    for(const auto& word : words_)
    {
        word->move_vertical (distance);
    }
}

