//
// Created by christian.heusser on 12.12.2019.
//

#ifndef _FLOOR_H_
#define _FLOOR_H_

#include <vector>
#include "Room.h"
#include "Door.h"

namespace sd {
    class Floor{

    protected:
        
        std::string name_;
        std::vector<Sp<Room>> rooms_;
        Sp<Room> start_room_;
    public:
        Floor(const std::string& name, sol::table& floor_data);
        virtual ~Floor() = default;
        
        Sp<Room> get_start_room();
        [[nodiscard]] Sp<Room> get_room(const std::string& name) const;
    };
}

#endif //_FLOOR_H_
