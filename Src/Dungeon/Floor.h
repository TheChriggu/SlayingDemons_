//
// Created by christian.heusser on 12.12.2019.
//

#ifndef SLAYINGDEMONS_FLOOR_H
#define SLAYINGDEMONS_FLOOR_H

#include <vector>
#include "Room.h"
#include "Door.h"

namespace sd {
    class Floor {

    protected:
        std::vector<Room*> rooms;
    public:
        Floor();
        ~Floor();

        Room* GetCurrentRoom();
        Room* GetStartRoom();
    };
}

#endif //SLAYINGDEMONS_FLOOR_H
