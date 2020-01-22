//
// Created by christian.heusser on 02.12.2019.
//

#ifndef SLAYINGDEMONS_FIGHT_H
#define SLAYINGDEMONS_FIGHT_H
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
    Fighter* player_;
    Monster* enemy_;
    //Attack GetAttack(Fighter* _fighter, sf::String _action, sf::String _modifier);

    public:
        Fight(Fighter* player, Monster* enemy);
        ~Fight();

        void full_turn(sf::String action, sf::String modifier);

        Monster* get_enemy();
    
    private:
        void player_turn(Attack* player_attack, Attack* enemy_attack);
        void enemy_turn(Attack* player_attack, Attack* enemy_attack);

    };
}


#endif //SLAYINGDEMONS_FIGHT_H
