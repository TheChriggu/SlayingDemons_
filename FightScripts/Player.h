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
        Vocabulary *actions;
        Vocabulary *modifiers;
        Vocabulary *world;

    };
}

#endif //SLAYINGDEMONS_PLAYER_H
