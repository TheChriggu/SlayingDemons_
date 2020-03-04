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
#include <Event/ColorsCreatedEventArgs.h>
#include <Event/SetStageEventArgs.h>

// TODO(FK): clean up name
sd::TextOutput::TextOutput(sf::Vector2f position, sf::Vector2f size, sf::Color color)
    : DrawableObject("text-output")
    , Subscriber()
    , position_(position)
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
        if (e->type == EventArgs::Type::COLORS_CREATED) {
            auto arg = std::dynamic_pointer_cast<ColorsCreatedEventArgs>(e);
           colors_ = Sp<Colors>(arg->colors);
        }
        if(e->type == EventArgs::Type::CURRENT_FONT_CHANGED)
        {
            reformat();
        }

        if(e->type == EventArgs::Type::CURRENT_COLOR_CHANGED)
        {
            reformat();
        }
        if(e->type == EventArgs::Type::SET_STAGE)
        {
            auto arg = std::dynamic_pointer_cast<SetStageEventArgs>(e);
            switch(arg->stage)
            {
                case 0:
                    max_size_.x = 1024;
                    max_size_.y = 435;
                    offset_ = sf::Vector2f(10, 55);
                    break;
                case 1:
                    max_size_.x = 1024;
                    max_size_.y = 435;
                    offset_ = sf::Vector2f(10, 55);
                    break;
                case 2:
                    max_size_.x = 1024;
                    max_size_.y = 500;
                    offset_ = sf::Vector2f(0, 15);
                    break;
                case 3:
                    max_size_.x = 1024;
                    max_size_.y = 500;
                    offset_ = sf::Vector2f(0, 15);
                    break;
            }
        }
        );
    
    REGISTER_EVENT_HANDLER();

    max_size_.x = size.x -20;
    max_size_.y = 435;

    text_tex_ = std::make_shared<sf::RenderTexture>();
    text_sprite_ = std::make_shared<sf::Sprite>();

    offset_ = sf::Vector2f(10, 55);

}

bool sd::TextOutput::setup() {
    ScriptEngine::get().register_all_timeable(1, 0.25, "print_line", &TextOutput::print_line, this);

    lines_.push_back(std::make_shared<FormattedLine>(
        "",
        sf::Vector2f(position_ + offset_),
        max_size_, fonts_, colors_));

    // Trigger TextOutput Created Event
    EventSystem::get().trigger(std::make_shared<TextOutputCreatedEventArgs>(weak_from_this()));

    auto table = ScriptEngine::get().get_script("config")->get_table("window")->as<sol::table>();
    text_tex_->create(table["size"]["x"], table["size"]["y"]);
    text_sprite_->setTexture(text_tex_->getTexture());

    return DrawableObject::setup ();
}

void sd::TextOutput::draw_to(Sp<sf::RenderTarget> window) const {
    text_tex_->clear(sf::Color::Transparent);

    for (const auto& line : lines_)
    {
        line->draw_to (text_tex_);
    }
    text_tex_->display();

    if (shader_procedure_)
    {

        shader_procedure_->process (window.get (), text_sprite_.get ());
    } else
    {
        window->draw(*text_sprite_);
    }
}

void sd::TextOutput::add_line(std::string string) {

    auto new_line = std::make_shared<FormattedLine>(
        string, sf::Vector2f(
                (position_ + offset_).x,
            lines_.back ()->get_rect ().top + lines_.back ()->get_rect ().height),
        max_size_,fonts_, colors_
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
    for(auto line : lines_)
    {
        line->handle(event);
    }
}

sf::Vector2f sd::TextOutput::get_position() {
    return position_;
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

void sd::TextOutput::reformat() {

    std::vector<std::string> lines;

    for (auto line : lines_)
    {
        lines.push_back(line -> get_line());
    }

    lines_.clear();

    lines_.push_back(std::make_shared<FormattedLine>(
            "",
            sf::Vector2f(position_ + offset_),
            max_size_, fonts_, colors_));

    for (auto line : lines)
    {
        add_line(line);
        std::cout << line << "\n";
    }
}




