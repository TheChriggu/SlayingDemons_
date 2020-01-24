//
// Created by christian.heusser on 09.01.2020.
//

#ifndef _LASTROOM_H_
#define _LASTROOM_H_

#include "Room.h"

namespace sd {
    class LastRoom: public Room {
    public:
        LastRoom();

        std::string get_enter_description() override;
    };
}

#endif //_LASTROOM_H_
