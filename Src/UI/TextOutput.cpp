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
            enqueue_line (arg->line);
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
        if(e->type == EventArgs::Type::RESET_OUTPUT_TIMER)
            {
                print_first_in_queue();
            }
        );


    REGISTER_EVENT_HANDLER();

    max_size_.x = size.x -20;
    max_size_.y = 435;

    text_tex_ = std::make_shared<sf::RenderTexture>();
    text_sprite_ = std::make_shared<sf::Sprite>();

    offset_ = sf::Vector2f(10, 55);

    line_queue_ = std::make_shared<std::vector<std::string>>();

    clock_ = std::make_shared<sf::Clock>();
    clock_->restart();
}

bool sd::TextOutput::setup() {

    //ScriptEngine::get().register_all_timeable(1, 0.25f, "print_line", &TextOutput::enqueue_line, this);
    ScriptEngine::get().register_all("print_line", &TextOutput::enqueue_line, this);

    lines_.push_back(std::make_shared<FormattedLine>(
        "",
        sf::Vector2f(position_ + offset_),
        max_size_, fonts_, colors_));

    // Trigger TextOutput Created Event
    EventSystem::get().trigger(std::make_shared<TextOutputCreatedEventArgs>(weak_from_this()));

    auto table = ScriptEngine::get().get_script("config")->get_table("window")->as<sol::table>();
    text_tex_->create(table["size"]["x"], table["size"]["y"]);
    text_sprite_->setTexture(text_tex_->getTexture());

    //one second interval between printing enqueued lines
    /*auto routine = std::make_shared<Routine>( Routine(nullptr, 1.5f,
                    std::function<bool(Sp<Routine>)>
                            (
                                [this](Sp<Routine> this_routine)
                                {
                                        print_first_in_queue();
                                        return Routine::restart;
                                }
                            )
                    )
    );

    RoutineManager::get().start_routine(routine);*/

    return DrawableObject::setup ();
}

void sd::TextOutput::draw_to(Sp<sf::RenderTarget> window) const {

    if(clock_->getElapsedTime().asSeconds() >= 0.85f)
    {
        clock_->restart();
        auto args = std::make_shared<EventArgs>();
        args->type = EventArgs::Type::RESET_OUTPUT_TIMER;
        EventSystem::get().trigger(args);
    }

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

void sd::TextOutput::enqueue_line(std::string string) {

    line_queue_->push_back(string);
}

void sd::TextOutput::print_first_in_queue() {

    if(line_queue_->size() > 0)
    {
        add_line(line_queue_->front());
        line_queue_->erase(line_queue_->begin());
    }
}

bool sd::TextOutput::has_queue() {
    return line_queue_->size() > 0;
}




