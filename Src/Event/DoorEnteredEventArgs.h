//
// Created by felix on 07.02.20.
//

#ifndef _DOORENTEREDEVENTARGS_H_
#define _DOORENTEREDEVENTARGS_H_

#include <string>
#include "EventArgs.h"

namespace sd {
    class DoorEnteredEventArgs : public EventArgs {
        public:
        
        explicit DoorEnteredEventArgs(std::string  room, std::string  door);
        ~DoorEnteredEventArgs() override = default;
        
        std::string room;
        std::string door;
    };
}

#endif //_DOORENTEREDEVENTARGS_H_
