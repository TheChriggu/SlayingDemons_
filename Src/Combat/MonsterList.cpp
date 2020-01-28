//
// Created by christian.heusser on 15.01.2020.
//

#include "MonsterList.h"

Sp<sd::MonsterList> sd::MonsterList::instance_ = nullptr;

sd::MonsterList::MonsterList() {
    if (!instance_)
    {
        instance_ = Sp<MonsterList>(this);

        auto table = FileInput::load_csv("../Resources/Tables/Monsters.csv");
        for(auto line : *table)
        {
            if(line[0] != "Name")
            {
                auto monster = std::make_shared<Monster>("../Resources/" + line[17]);
                //action->SetName(line[0]);
                monster->SetBaseStats({stof(line[1]),stof(line[2]),stof(line[3])
                                         ,stof(line[4]),stof(line[5]),stof(line[6])
                                         ,stof(line[7]),stof(line[8])}
                                         ,{stof(line[9]),stof(line[10]),stof(line[11])
                                              ,stof(line[12]),stof(line[13]),stof(line[14])
                                              ,stof(line[15]),stof(line[16])});

                auto modifiers = split_by_slash(line[18]);
                auto actions = split_by_slash(line[19]);

                for(const auto& modifier : modifiers)
                {
                    if (!modifier.empty())
                    {
                        monster->AddModifier(modifier);
                    }
                }
                for(const auto& action : actions)
                {
                    if (!action.empty())
                    {
                        monster->AddAction(action);
                    }

                }
                monsters_.emplace(line[0], monster);
            }
        }
    }
}

Sp<sd::MonsterList> sd::MonsterList::get() {
    return instance_;
}

Sp<sd::Monster> sd::MonsterList::get_monster(const std::string& name) {
    return monsters_.at(name);;
}

std::vector<std::string> sd::MonsterList::split_by_slash(std::string string) {
    std::vector<std::string> ret_val;
    std::string delimiter = "/";

    size_t pos = 0;
    std::string token;
    while ((pos = string.find(delimiter)) != std::string::npos) {
        token = string.substr(0, pos);

        ret_val.emplace_back(token);
        string.erase(0, pos + delimiter.size());
    }
    ret_val.emplace_back(string);

    return ret_val;
}