//
// Created by christian.heusser on 15.01.2020.
//

#ifndef _MONSTERLIST_H_
#define _MONSTERLIST_H_

#include <map>
#include "Monster.h"
#include "../IO/FileInput.h"

namespace sd {
    class MonsterList {
        static Sp<sd::MonsterList> instance_;
        std::map<std::string, Sp<Monster>> monsters_;

    public:
        MonsterList();
        ~MonsterList() = default;

        static Sp<MonsterList> get();
        Sp<Monster> get_monster(const std::string& name);

        static std::vector<std::string> split_by_slash(std::string string);

    };
}


#endif //_MONSTERLIST_H_
