//
// Created by christian.heusser on 08.01.2020.
//

#include "WalkedThroughDoorEventArgs.h"
#include <utility>

sd::WalkedThroughDoorEventArgs::WalkedThroughDoorEventArgs(Wp<sd::Door> door)
    : door(std::move(door)) {
    this->type = EventArgs::Type::WALKED_THROUGH_DOOR;
}
