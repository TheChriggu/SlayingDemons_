//
// Created by christian.heusser on 12.12.2019.
//all fault with the name of this class goes to Felix.
//

#ifndef _PLAYERSTATE_H_
#define _PLAYERSTATE_H_

#include "Dungeon/Floor.h"
#include "Dungeon/Room.h"
#include "Combat/Fight.h"
#include "PlayerVocabulary.h"

namespace sd {
    class PlayerState : public Subscriber {
    private:
        Sp<Room> current_room_;
        Sp<Floor> current_floor_;
        Sp<Fight> fight_;
        Sp<Fighter> player_;
        
        Sp<PlayerVocabulary> player_vocabulary_;

    public:
        PlayerState();
        ~PlayerState() override = default;

        Sp<Room> get_current_room();
        Sp<Fight> get_fight();
        bool is_fighting();

        void set_current_room(Sp<Room> room);
        void set_current_floor(Sp<Floor> floor);
        void start_new_fight(const std::string& enemy_name);

        Sp<PlayerVocabulary> get_player_vocabulary();
        void handle(std::shared_ptr<EventArgs> e) override;

    };
}

#endif //_PLAYERSTATE_H_
