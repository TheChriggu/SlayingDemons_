//
// Created by christian.heusser on 08.01.2020.
//

#include "WalkedThroughDoorEventArgs.h"

sd::WalkedThroughDoorEventArgs::WalkedThroughDoorEventArgs(sd::Door *_door) {
    this->type = EventArgs::Type::WALKED_THROUGH_DOOR;
    this->door = _door;
}
