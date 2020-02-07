//
// Created by felix on 07.02.20.
//

#include "DoorEnteredEventArgs.h"
#include <utility>

sd::DoorEnteredEventArgs::DoorEnteredEventArgs(std::string room, std::string door)
    : room(std::move(room))
    , door(std::move(door))
{
    type = EventArgs::Type::DOOR_ENTERED;
}
