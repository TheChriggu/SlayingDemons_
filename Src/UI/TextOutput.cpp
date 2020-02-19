//
// Created by christian.heusser on 06.11.2019.
//

#include "TextOutput.h"
#include <iostream>
#include <memory>
#include <Event/EventSystem.h>
#include <Event/TextOutputCreatedEventArgs.h>
#include <Event/LineToOutputEventArgs.h>
#include <ScriptEngine/ScriptEngine.h>
#include <Event/FontsCreatedEventArgs.h>

//TODO(CH): Lines have to move up, when max is reached.
// TODO(FK): clean up name
sd::TextOutput::TextOutput(sf::Vector2f position, sf::Vector2f size, sf::Color color)
    : DrawableObject("text-output")
    , Subscriber()
    , start_position_(position)
{

    event_handler_ = CREATE_EVENT_HANDLER(
        if (e->type == EventArgs::Type::LINE_TO_OUTPUT) {
            auto arg = std::dynamic_pointer_cast<LineToOutputEventArgs>(e);
            add_line (arg->line);
        }
        if (e->type == EventArgs::Type::FONTS_CREATED) {
            auto arg = std::dynamic_pointer_cast<FontsCreatedEventArgs>(e);
            fonts_ = Sp<Font>(arg->fonts);
        }
        );
    
    REGISTER_EVENT_HANDLER();

    max_size_ = size;
    max_size_.y = 450; //TODO: This is not good
}

bool sd::TextOutput::setup() {
  ScriptEngine::get().register_all ("print_line", &TextOutput::print_line, this);

    //font_ = std::make_shared<sf::Font>();

    /*if (!font_->loadFromFile("../Resources/Fonts/comic.ttf"))
    {
        std::cout << "Could not load Font!\n";
        return false;
    }*/

    lines_.push_back(std::make_shared<FormattedLine>(
        "",
        sf::Vector2f(start_position_ + sf::Vector2f(20, 20)),
        max_size_, fonts_));

    // Trigger TextOutput Created Event
    EventSystem::get().trigger(std::make_shared<TextOutputCreatedEventArgs>(weak_from_this()));

    return DrawableObject::setup ();
}

void sd::TextOutput::draw_to(Sp<sf::RenderTarget> window) const {
    // TODO(CH): There is no need to query this condition. Removed because causing Output to not be drawing anymore
    /*if (!sf::Shader::isAvailable())
    {
        for (const auto& line : lines) {
            line->drawTo(window, window);
        }
    }*/
    for (const auto& line : lines_) {
        line->draw_to (window);
    }
}

void sd::TextOutput::add_line(std::string string) {

    auto new_line = std::make_shared<FormattedLine>(
        string, sf::Vector2f(
            lines_.back ()->get_rect ().left,
            lines_.back ()->get_rect ().top + lines_.back ()->get_rect ().height),
        max_size_,fonts_
    );

    //format line
    lines_.push_back(new_line);
    while(get_size ().y > max_size_.y)
    {
        float distance = lines_.front ()->get_rect ().height;
        move_vertical (-distance);
        lines_.pop_front();
    }

}

void sd::TextOutput::print_line(std::string string) {
    //sf::String temp(string);
  add_line (string);
}

void sd::TextOutput::handle(sf::Event event) {

}

sf::Vector2f sd::TextOutput::get_position() {
    //TODO(CH): GetPosition function. Based on lines? or saved in variable?
    return sf::Vector2f();
}

sf::Vector2f sd::TextOutput::get_size() {
    sf::Vector2f ret_val;
    ret_val.x = 0;
    ret_val.y = 0;

    for (const auto& line : lines_)
    {
        sf::FloatRect rect = line->get_rect ();
        if (rect.width > ret_val.x)
        {
            ret_val.x = rect.width;
        }

        ret_val.y += rect.height;
    }

    return ret_val;
}

void sd::TextOutput::move_vertical(float distance) {
    for(const auto& line : lines_){
        line->move_vertical (distance);
    }
}




