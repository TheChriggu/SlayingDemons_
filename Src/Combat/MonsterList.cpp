//
// Created by christian.heusser on 15.01.2020.
//

#include "MonsterList.h"

sd::MonsterList* sd::MonsterList::instance = nullptr;

sd::MonsterList::MonsterList() {
    if (!instance)
    {
        instance = this;

        auto table = FileInput::LoadCSV("../Resources/Tables/Monsters.csv");
        for(auto line : *table)
        {
            if(line[0] != "Name")
            {
                Monster* monster = new Monster("../Resources/" + line[17]);
                //action->SetName(line[0]);
                monster->SetBaseStats({stof(line[1]),stof(line[2]),stof(line[3])
                                         ,stof(line[4]),stof(line[5]),stof(line[6])
                                         ,stof(line[7]),stof(line[8])}
                                         ,{stof(line[9]),stof(line[10]),stof(line[11])
                                              ,stof(line[12]),stof(line[13]),stof(line[14])
                                              ,stof(line[15]),stof(line[16])});


                monsters.emplace(line[0], monster);
            }
        }
    }
}

sd::MonsterList *sd::MonsterList::Get() {
    return instance;
}

sd::Monster *sd::MonsterList::GetMonster(std::string name) {
    return monsters.at(name);;
}

