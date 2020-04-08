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

        bool door_fight_done;

    public:
        PlayerState();
        ~PlayerState() override = default;

        Sp<Room> get_current_room();
        Sp<Floor> get_current_floor();
        Sp<Fight> get_fight();
        bool is_fighting();

        void set_current_room(Sp<Room> room);
        void set_current_floor(Sp<Floor> floor);
        void start_new_fight_room_object(const std::string& enemy_name, const std::string& room_object_to_remove_on_defeat);
        void start_new_fight(const std::string& enemy_name);

        Sp<PlayerVocabulary> get_player_vocabulary();

        void save_current_vocab();
        void load_vocab();

        void player_door_fight();

        void check_for_self_destruct_added();

    };
}

#endif //_PLAYERSTATE_H_
