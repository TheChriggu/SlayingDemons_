//
// Created by christian.heusser on 02.03.2020.
//

#include "Colors.h"
#include "../Event/SetStageEventArgs.h"
#include <Event/EventSystem.h>

sd::Colors::Colors() {
    current_color_ = sf::Color::Black;

    event_handler_ = CREATE_EVENT_HANDLER(
                             if (e->type == EventArgs::Type::SET_STAGE) {
                                 auto arg = std::dynamic_pointer_cast<SetStageEventArgs>(e);
                                 switch(arg->stage)
                                 {
                                     case 0:
                                         current_color_ = sf::Color::Black;
                                         current_input_color_ = sf::Color::Black;
                                         break;

                                     case 1:
                                         current_color_ = sf::Color::White;
                                         current_input_color_ = sf::Color::Green;
                                         break;
                                 }

                                 auto args = std::make_shared<EventArgs>();
                                 args->type = sd::EventArgs::Type::CURRENT_COLOR_CHANGED;
                                 EventSystem::get().trigger(args);
                             }
                     );
    REGISTER_EVENT_HANDLER();
}

sf::Color sd::Colors::GetCurrentColor() {
    return current_color_;
}

sd::Colors::~Colors() {

}

sf::Color sd::Colors::GetCurrentInputColor() {
    return current_input_color_;
}
