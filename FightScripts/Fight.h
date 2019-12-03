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

namespace sd {

    class Fight {
    private:
    Player* player;
    Monster* enemy;
    //Attack GetAttack(Fighter* _fighter, sf::String _action, sf::String _modifier);

    public:
        Fight(Player* _player, Monster* _enemy);
        ~Fight();

        void FullTurn(sf::String _action, sf::String _modifier);

    };
}


#endif //SLAYINGDEMONS_FIGHT_H
