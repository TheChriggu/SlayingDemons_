//
// Created by christian.heusser on 07.11.2019.
//

#include "FormattedLine.h"
#include <memory>


sd::FormattedLine::FormattedLine(std::string string, sf::Vector2f position, sf::Vector2f max_size, Sp<Font> fonts,  Sp<Colors> colors) {
    sd::Format format;
    format.style_ = sf::Text::Italic;
    format.size_ = 25;
    format.on_click_text_ = "";
    format.color_ = sf::Color::Red;
    format.font_ = fonts->GetFont("fantasy");

    position_ = position;
    max_size_ = max_size;
    words_.push_back(std::make_shared<FormattedWord>("", position, format, fonts, colors));
    format_line (string, fonts, colors);
}

void sd::FormattedLine::draw_to(const Sp<sf::RenderTarget>& window) {
    for (const auto& word : words_) {
        word->draw_to (window);
    }
}

void sd::FormattedLine::format_line(std::string string, Sp<Font> fonts, Sp<Colors> colors) {
    sd::Format format;
    format.style_ = sf::Text::Regular;
    format.size_ = 20;
    format.on_click_text_ = "";
    format.color_ = colors->GetCurrentColor();
    format.font_ = fonts->GetCurrentFont();


    //remove leading spaces


    sf::Vector2f next_position =  sf::Vector2f(get_rect ().left, get_rect ().top + get_rect ().height);
    
    std::vector<std::string> string_vector;
    strtk::parse(string, " ", string_vector, strtk::split_options::include_1st_delimiter);
    
    for(auto word : string_vector)
        {
                    Sp<FormattedWord> newWord = std::make_shared<FormattedWord> (FormattedWord (word, next_position, format, fonts, colors));
                    next_position.x += newWord->get_rect ().width;
                    if (next_position.x > max_size_.x)
                        {
                            next_position = sf::Vector2f (get_rect ().left, get_rect ().top + get_rect ().height);
                            newWord->set_position (next_position);
                            next_position.x += newWord->get_rect ().width;
                        }
                
                    words_.push_back (newWord);
        }
}

sf::FloatRect sd::FormattedLine::get_rect(){
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

void sd::FormattedLine::move_vertical(float distance) {
    position_.y += distance;
    for(const auto& word : words_)
    {
        word->move_vertical (distance);
    }
}

void sd::FormattedLine::handle(sf::Event event) {
    for(auto word : words_)
    {
        word->handle(event);
    }
}

void sd::FormattedLine::set_font_size_color(Sp<Font> fonts, int size, Sp<Colors> colors) {
    sd::Format format;
    format.size_ = 20;
    format.color_ = colors->GetCurrentColor();
    format.font_ = fonts->GetCurrentFont();
    for(const auto& word : words_)
    {
        word->set_font_size_color (format);
    }
}

void sd::FormattedLine::set_font(Sp<sf::Font> font) {
    for(const auto& word : words_)
    {
        word->set_font(font);
    }
}

void sd::FormattedLine::set_size(int size) {
    for(const auto& word : words_)
    {
        word->set_size(size);
    }
}

void sd::FormattedLine::set_color(sf::Color color) {
    for(const auto& word : words_)
    {
        word->set_color(color);
    }
}

std::string sd::FormattedLine::get_line() {
    std::string ret_val = "";
    for(auto word : words_)
    {
        ret_val += word->get_raw();
        ret_val += " ";
    }

    return ret_val;
}



