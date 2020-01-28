//
// Created by christian.heusser on 28.11.2019.
//

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Vocabulary.h"
#include "Fighter.h"

namespace sd {
    class Player : public Fighter{
    private:
        //std::vector<sf::String>* actions;
        //std::vector<sf::String>* modifiers;
        //std::vector<sf::String>* world;

    public:
        Player() = default;
        ~Player() override = default;

        bool has_word(std::string word);
        void add_action(std::string action);
        void add_modifier(std::string modifier);
        void add_world(std::string word);
    };
}

#endif //_PLAYER_H_
