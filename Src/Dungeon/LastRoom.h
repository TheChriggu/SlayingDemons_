//
// Created by christian.heusser on 09.01.2020.
//

#ifndef SLAYINGDEMONS_LASTROOM_H
#define SLAYINGDEMONS_LASTROOM_H

#include "Room.h"

namespace sd {
    class LastRoom: public Room {
    public:

        std::string GetEnterDescription() override;
    };
}

#endif //SLAYINGDEMONS_LASTROOM_H
