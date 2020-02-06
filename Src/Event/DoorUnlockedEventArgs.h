//
// Created by christian.heusser on 06.02.2020.
//

#ifndef SLAYINGDEMONS_DOORUNLOCKEDEVENTARGS_H
#define SLAYINGDEMONS_DOORUNLOCKEDEVENTARGS_H

#include "EventArgs.h"
#include <iostream>


namespace sd {
    class DoorUnlockedEventArgs: public EventArgs {
    public:
        explicit DoorUnlockedEventArgs(std::string room_name, std::string door_name);
        ~DoorUnlockedEventArgs() override = default;

        std::string room_name;
        std::string door_name;
    };
}

#endif //SLAYINGDEMONS_DOORUNLOCKEDEVENTARGS_H
