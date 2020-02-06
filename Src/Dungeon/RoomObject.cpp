//
// Created by christian.heusser on 10.12.2019.
//

#include <Event/LineToOutputEventArgs.h>
#include <Event/EventSystem.h>
#include <utility>
#include "RoomObject.h"

sd::RoomObject::RoomObject(std::string name, sf::Vector2i position, sol::function be_interacted_with_signal,
        sol::function be_opened_signal, sol::function be_inspected_signal, sol::function be_fought_signal,
        sol::function be_entered_signal)
    : name_(std::move(name))
    , position_on_tile_map_(position)
    , be_interacted_with_signal_(std::move(be_interacted_with_signal))
    , be_opened_signal_(std::move(be_opened_signal))
    , be_inspected_signal_(std::move(be_inspected_signal))
    , be_fought_signal_(std::move(be_fought_signal))
    , be_entered_signal_(std::move(be_entered_signal))
{ }

void sd::RoomObject::be_interacted_with()
{

    
    if (be_interacted_with_signal_.valid())
    {
        be_interacted_with_signal_();
    } else {
        std::shared_ptr<LineToOutputEventArgs> args;
        args = std::make_shared<LineToOutputEventArgs>("You try to interact with the " + name_ + ".");
        EventSystem::get().trigger(args);
        args = std::make_shared<LineToOutputEventArgs>("No reaction.");
        EventSystem::get().trigger(args);
    }
}

void sd::RoomObject::be_opened()
{


    if (be_opened_signal_.valid())
    {
        be_opened_signal_();
    } else {
        std::shared_ptr<LineToOutputEventArgs> args;
        args = std::make_shared<LineToOutputEventArgs>("You try to open the " + name_ + ".");
        EventSystem::get().trigger(args);
        args = std::make_shared<LineToOutputEventArgs>("This will never work.");
        EventSystem::get().trigger(args);
    }
}

void sd::RoomObject::be_inspected()
{
    if (be_inspected_signal_.valid())
    {
        be_inspected_signal_();
    } else {
        std::shared_ptr<LineToOutputEventArgs> args;
        args = std::make_shared<LineToOutputEventArgs>("You try to inspect the " + name_ + ".");
        EventSystem::get().trigger(args);
        args = std::make_shared<LineToOutputEventArgs>("There appears nothing to be special about it.");
        EventSystem::get().trigger(args);
    }
}

void sd::RoomObject::be_fought()
{

    if (be_fought_signal_.valid())
    {
        be_fought_signal_();
    } else {
        std::shared_ptr<LineToOutputEventArgs> args;
        args = std::make_shared<LineToOutputEventArgs>("You attack the " + name_ + ".");
        EventSystem::get().trigger(args);

        args = std::make_shared<LineToOutputEventArgs>("That's useless.");
        EventSystem::get().trigger(args);
    }
}

void sd::RoomObject::be_entered()
{

    if (be_entered_signal_.valid())
    {
        be_entered_signal_();
    } else {
        std::shared_ptr<LineToOutputEventArgs> args;
        args = std::make_shared<LineToOutputEventArgs>("You try to enter the " + name_ + ".");
        EventSystem::get().trigger(args);

        args = std::make_shared<LineToOutputEventArgs>("The fact that a " + name_ + " is a solid object with common physical properties prevents you from continuing on this endeavor.");
        EventSystem::get().trigger(args);
    }
}



void sd::RoomObject::on_destroyed()
{

}

