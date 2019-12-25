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
    Fighter* player;
    Monster* enemy;
    //Attack GetAttack(Fighter* _fighter, sf::String _action, sf::String _modifier);
    Stats MinToZero(Stats stats);

    public:
        Fight(Fighter* _player, Monster* _enemy);
        ~Fight();

        void FullTurn(sf::String _action, sf::String _modifier, TextOutput* output);

    };
}


#endif //SLAYINGDEMONS_FIGHT_H
