//
// Created by christian.heusser on 04.02.2020.
//

#include "Font.h"
#include <Event/EventSystem.h>
#include <Event/FontsCreatedEventArgs.h>
#include "../Event/SetStageEventArgs.h"

sd::Font::Font() {
    fantasy_font_ = std::make_shared<sf::Font>();
    cyber_font_ = std::make_shared<sf::Font>();
    code_font_ = std::make_shared<sf::Font>();
    transition_font_ = std::make_shared<sf::Font>();
    book_font = std::make_shared<sf::Font>();
    ai_font_ = std::make_shared<sf::Font>();

    fantasy_font_->loadFromFile("../Resources/Fonts/Merriweather-Light.ttf");
    transition_font_->loadFromFile("../Resources/Fonts/MerriweatherSans-Light.ttf");
    cyber_font_->loadFromFile("../Resources/Fonts/RobotoMono-Regular.ttf");
    code_font_->loadFromFile("../Resources/Fonts/VT323-Regular.ttf");
    book_font->loadFromFile("../Resources/Fonts/IMFellEnglishSC-Regular.ttf");
    ai_font_->loadFromFile("../Resources/Fonts/Quantico-Regular.ttf");


    current_font_ = fantasy_font_;

    event_handler_ = CREATE_EVENT_HANDLER(
                             if (e->type == EventArgs::Type::SET_STAGE) {
                                 auto arg = std::dynamic_pointer_cast<SetStageEventArgs>(e);
                                 switch(arg->stage)
                                 {
                                     case 0:
                                         current_font_ = fantasy_font_;
                                         break;

                                     case 1:
                                         current_font_ = transition_font_;
                                         break;

                                     case 2:
                                         current_font_ = transition_font_;
                                         break;

                                     case 3:
                                         current_font_ = cyber_font_;
                                         break;
                                 }

                                 auto args = std::make_shared<EventArgs>();
                                 args->type = sd::EventArgs::Type::CURRENT_FONT_CHANGED;
                                 EventSystem::get().trigger(args);
                             }

                             if (e->type == EventArgs::Type::SELF_DESTRUCT) {
                                 fantasy_font_.reset();
                                 cyber_font_.reset();
                                 code_font_.reset();
                                 transition_font_.reset();
                                 book_font.reset();
                                 ai_font_.reset();
                                 current_font_.reset();
                             }
                     );

    REGISTER_EVENT_HANDLER();
}

sd::Font::~Font() {

}

Sp<sf::Font> sd::Font::GetFont(std::string font) {
    if (font == "fantasy")
    {
        return fantasy_font_;
    }
    if (font == "transition")
    {
        return transition_font_;
    }
    if (font == "cyber")
    {
        return cyber_font_;
    }
    if (font == "code")
    {
        return code_font_;
    }
    if (font == "ai")
    {
        return ai_font_;
    }
    if (font == "book")
    {
        return book_font;
    }
    if (font == "current")
    {
        return GetCurrentFont();
    }
    return fantasy_font_;
}

Sp<sf::Font> sd::Font::GetCurrentFont() {
    return current_font_;
}
