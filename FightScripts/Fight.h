//
// Created by christian.heusser on 02.12.2019.
//

#ifndef SLAYINGDEMONS_FIGHT_H
#define SLAYINGDEMONS_FIGHT_H
#include "Fighter.h"
namespace sd {

    class Fight {
    private:
    Fighter* player;
    Fighter* enemy;

    public:
        Fight(Fighter* _player, Fighter* _enemy);
        ~Fight();



    };
}


#endif //SLAYINGDEMONS_FIGHT_H
