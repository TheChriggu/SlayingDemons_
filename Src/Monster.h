//
// Created by christian.heusser on 03.12.2019.
//

#ifndef SLAYINGDEMONS_MONSTER_H
#define SLAYINGDEMONS_MONSTER_H

#include "Fighter.h"
#include "Vocabulary.h"
#include <cstdlib>

namespace sd
{
    class Monster : public Fighter{
    private:
        std::vector<sf::String>* actions;
        std::vector<sf::String>* modifiers;

    public:
        Monster();
        ~Monster();

        sf::String GetAction();
        sf::String GetModifier();

        void AddAction(sf::String action);
        void AddModifier(sf::String modifier);
    };
}

#endif //SLAYINGDEMONS_MONSTER_H
