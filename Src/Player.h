//
// Created by christian.heusser on 28.11.2019.
//

#ifndef SLAYINGDEMONS_PLAYER_H
#define SLAYINGDEMONS_PLAYER_H
#include "Vocabulary.h"
#include "Fighter.h"

namespace sd {
    class Player : public Fighter{
    private:
        std::vector<sf::String>* actions;
        std::vector<sf::String>* modifiers;
        std::vector<sf::String>* world;

    public:
        Player();
        ~Player();

        bool HasWord(sf::String word);
        void AddAction(sf::String action);
        void AddModifier(sf::String modifier);
        void AddWorld(sf::String word);
    };
}

#endif //SLAYINGDEMONS_PLAYER_H
