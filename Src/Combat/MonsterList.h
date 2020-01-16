//
// Created by christian.heusser on 15.01.2020.
//

#ifndef SLAYINGDEMONS_MONSTERLIST_H
#define SLAYINGDEMONS_MONSTERLIST_H
#include <map>
#include "Monster.h"
#include "../IO/FileInput.h"

namespace sd {
    class MonsterList {
        static sd::MonsterList* instance;
        std::map<std::string, Monster*> monsters;

    public:
        MonsterList();
        ~MonsterList() = default;

        static MonsterList* Get();
        Monster* GetMonster(std::string name);

        std::vector<std::string> SplitBySlash(std::string string);

    };
}


#endif //SLAYINGDEMONS_MONSTERLIST_H
