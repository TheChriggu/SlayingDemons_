//
// Created by christian.heusser on 06.02.2020.
//

#include "DoorUnlockedEventArgs.h"

sd::DoorUnlockedEventArgs::DoorUnlockedEventArgs(std::string room_name, std::string door_name)
        : door_name(std::move(door_name))
        , room_name(std::move(room_name))
{
    this->type = EventArgs::Type::DOOR_UNLOCKED;
}