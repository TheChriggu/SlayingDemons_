//
// Created by felix on 27.11.19.
//

#ifndef _WORLD_H_
#define _WORLD_H_

#include "Core/Manageable.h"
#include "PlayerState.h"

namespace sd {
    class World : public Manageable, public Subscriber {
        
        Sp<PlayerState> player_state_;
        
        std::vector<Sp<Floor>> floors_;
        
    public:
        World();
        ~World() override = default;

        bool setup() override;
        void shutdown() override;
        
        void handle(Sp<EventArgs> e) override;

        void unlock_door(std::string room_name, std::string door_name);

        void set_floor(std::string floor_name);
    };
}


#endif //_WORLD_H_
