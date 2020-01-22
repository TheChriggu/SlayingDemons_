//
// Created by christian.heusser on 10.12.2019.
//

#include <Event/LineToOutputEventArgs.h>
#include <Event/EventSystem.h>
#include <utility>
#include "RoomObject.h"

sd::RoomObject::RoomObject(std::string name, sf::Vector2i position, sol::function be_interacted_with_signal)
    : name_(std::move(name))
    , position_on_tile_map_(position)
    , be_interacted_with_signal_(std::move(be_interacted_with_signal))
{ }

void sd::RoomObject::be_interacted_with()
{
    std::shared_ptr<LineToOutputEventArgs> args;
    args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("You try to interact with the " + name_ + "."));
    EventSystem::Get().Trigger(args);
    
    if (be_interacted_with_signal_.valid())
    {
        be_interacted_with_signal_();
    } else {
        args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("Nothing happens."));
        EventSystem::Get().Trigger(args);
    }
    
}
void sd::RoomObject::on_destroyed()
{

}

