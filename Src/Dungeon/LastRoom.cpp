//
// Created by christian.heusser on 09.01.2020.
//

#include "LastRoom.h"

std::string sd::LastRoom::GetEnterDescription() {
    return "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

sd::LastRoom::LastRoom() : Room(){
    is_last = true;
}
