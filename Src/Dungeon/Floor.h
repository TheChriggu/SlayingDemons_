//
// Created by christian.heusser on 12.12.2019.
//

#ifndef _FLOOR_H_
#define _FLOOR_H_

#include <vector>
#include "Room.h"
#include "Door.h"

namespace sd {
    class Floor : public Manageable{

    protected:
        std::vector<Sp<Room>> rooms_;
        Sp<Room> start_room_;
    public:
        Floor();
        ~Floor() override;
        
        bool setup() override;
        void shutdown() override;
        
        Sp<Room> get_start_room();
        [[nodiscard]] Sp<Room> get_room(const std::string& name) const;
    };
}

#endif //_FLOOR_H_
