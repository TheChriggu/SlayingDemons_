//
// Created by christian.heusser on 03.12.2019.
//

#ifndef _MONSTER_H_
#define _MONSTER_H_

#include "Fighter.h"
#include "Vocabulary.h"
#include <cstdlib>

namespace sd
{
    class Monster : public Fighter{
    private:
        std::vector<std::string> actions_;
        std::vector<std::string> modifiers_;
        std::string path_to_portrait_;
        std::string alias_;
        std::string gender_;

    public:
        explicit Monster(std::string path_to_portrait, std::string alias, std::string gender);
        ~Monster() override = default;

        std::string get_action();
        std::string get_modifier();

        void add_action(const std::string& action);
        void add_modifier(const std::string& modifier);

        std::string get_path_to_portrait();
        std::string get_alias();
        std::string get_gender();
    };
}

#endif //_MONSTER_H_
