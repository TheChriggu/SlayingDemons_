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

namespace sd {

    class Fight {
    private:
    Player* player;
    Fighter* enemy;
    //Attack GetAttack(Fighter* _fighter, sf::String _action, sf::String _modifier);

    public:
        Fight(Fighter* _player, Fighter* _enemy);
        ~Fight();

        void FullTurn(sf::String _action, sf::String _modifier);

    };
}


#endif //SLAYINGDEMONS_FIGHT_H
