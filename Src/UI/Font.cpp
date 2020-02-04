//
// Created by christian.heusser on 04.02.2020.
//

#include "Font.h"
#include <Event/EventSystem.h>
#include <Event/FontsCreatedEventArgs.h>

sd::Font::Font() {
    fantasy_font_ = std::make_shared<sf::Font>();
    cyber_font_ = std::make_shared<sf::Font>();

    fantasy_font_->loadFromFile("../Resources/Fonts/comic.ttf");
    cyber_font_->loadFromFile("../Resources/Fonts/Alef-Regular.ttf");


    EventSystem::get().trigger(std::make_shared<FontsCreatedEventArgs>(Sp<Font>(this)));

}

sd::Font::~Font() {

}

Sp<sf::Font> sd::Font::GetFont(std::string font) {
    if (font == "fantasy")
    {
        return fantasy_font_;
    }
    if (font == "cyber")
    {
        return cyber_font_;
    }
    return fantasy_font_;
}
