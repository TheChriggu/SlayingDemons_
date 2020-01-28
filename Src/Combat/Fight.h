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
    //Attack GetAttack(Fighter* _fighter, sf::String _action, sf::String _modifier);

    public:
        Fight(Sp<Fighter> player, Sp<Monster> enemy);
        virtual ~Fight() = default;

        void full_turn(std::string action, std::string modifier);

        Sp<Monster> get_enemy();
    
    private:
        void player_turn(const Sp<Attack>& player_attack, const Sp<Attack>& enemy_attack);
        void enemy_turn(const Sp<Attack>& player_attack, const Sp<Attack>& enemy_attack);

    };
}


#endif //_FIGHT_H_
