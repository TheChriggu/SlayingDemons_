//
// Created by christian.heusser on 03.12.2019.
//

#ifndef SLAYINGDEMONS_ATTACK_H
#define SLAYINGDEMONS_ATTACK_H
#include "Fighter.h"
#include "Modifier.h"
#include "Action.h"

namespace sd
{
    class Attack {
    private:
        Fighter* fighter;
        Modifier* modifier;
        Action* action;
    public:
        Attack(Fighter* _fighter, Modifier* _modifier, Action* _action);
        ~Attack();

        Stats GetStats();

        sf::String GetSentenceSecondPerson();
        sf::String GetSentenceThirdPerson();
    };
}



#endif //SLAYINGDEMONS_ATTACK_H
