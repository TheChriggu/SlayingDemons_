//
// Created by christian.heusser on 10.12.2019.
//

#include <Event/LineToOutputEventArgs.h>
#include <Event/EventSystem.h>
#include <utility>
#include "RoomObject.h"

sd::RoomObject::RoomObject(std::string name, sf::Vector2i position, Sp<FunctionCollection> function_collection)
    : name_(std::move(name))
    , position_on_tile_map_(position)
    , function_collection_(std::move(function_collection))
{ }

void sd::RoomObject::be_opened()
{


    if (function_collection_->is_opened_valid())
    {
        function_collection_->invoke_opened();
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
    if (function_collection_->is_inspected_valid())
    {
        function_collection_->invoke_inspected();
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

    if (function_collection_->is_fought_valid())
    {
        function_collection_->invoke_fought();
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

    if (function_collection_->is_entered_valid())
    {
        function_collection_->invoke_entered();
    } else {
        std::shared_ptr<LineToOutputEventArgs> args;
        args = std::make_shared<LineToOutputEventArgs>("You try to enter the " + name_ + ".");
        EventSystem::get().trigger(args);

        args = std::make_shared<LineToOutputEventArgs>("The fact that a " + name_ + " is a solid object with common physical properties prevents you from continuing on this endeavor.");
        EventSystem::get().trigger(args);
    }
}

void sd::RoomObject::be_destroyed() {
    if (function_collection_->is_destroyed_valid())
    {
        function_collection_->invoke_destroyed();
    }
}


