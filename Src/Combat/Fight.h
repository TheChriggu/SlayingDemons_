//
// Created by christian.heusser on 02.12.2019.
//

#ifndef _FIGHT_H_
#define _FIGHT_H_

#include "Fighter.h"
#include "SFML/Graphics.hpp"
#include "Vocabulary.h"
#include "Attack.h"
#include "Player.h"
#include "Monster.h"
#include "UI/TextOutput.h"

namespace sd {

    class Fight {
    private:
    Sp<Fighter> player_;
    Sp<Monster> enemy_;

    public:
        Fight(Sp<Fighter> player, Sp<Monster> enemy);
        virtual ~Fight() = default;

        void full_turn(std::string action, std::string modifier);

        Sp<Monster> get_enemy();
    
    private:
        void player_turn(const Sp<Attack>& player_attack);
        void enemy_turn(const Sp<Attack>& enemy_attack);
        std::string get_enemy_pronoun(std::string declination);

    };
}


#endif //_FIGHT_H_
