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

    fantasy_font_->loadFromFile("../Resources/Fonts/comic.ttf");
    cyber_font_->loadFromFile("../Resources/Fonts/Alef-Regular.ttf");
    if(!(code_font_->loadFromFile("../Resources/Fonts/trebuc.ttf")))
    {
        std::cout << "could not load code font.\n";
    }

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
                                         current_font_ = cyber_font_;
                                         break;
                                 }

                                 auto args = std::make_shared<EventArgs>();
                                 args->type = sd::EventArgs::Type::CURRENT_FONT_CHANGED;
                                 EventSystem::get().trigger(args);
                             }
                     );

    REGISTER_EVENT_HANDLER();


    //EventSystem::get().trigger(std::make_shared<FontsCreatedEventArgs>(weak_from_this()));

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
    if (font == "code")
    {
        return code_font_;
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
