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
        std::string pathToPortrait;

    public:
        Monster(std::string _pathToPortrait);
        ~Monster();

        sf::String GetAction();
        sf::String GetModifier();

        void AddAction(sf::String action);
        void AddModifier(sf::String modifier);

        std::string GetPathToPortrait();
    };
}

#endif //SLAYINGDEMONS_MONSTER_H
