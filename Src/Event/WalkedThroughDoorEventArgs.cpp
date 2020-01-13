//
// Created by christian.heusser on 08.01.2020.
//

#include "WalkedThroughDoorEventArgs.h"

sd::WalkedThroughDoorEventArgs::WalkedThroughDoorEventArgs(sd::Door *_door) {
    this->type = EventArgs::Type::WalkedThroughDoor;
    this->door = _door;
}
