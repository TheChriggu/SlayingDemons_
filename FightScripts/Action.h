//
// Created by christian.heusser on 28.11.2019.
//

#ifndef SLAYINGDEMONS_ACTION_H
#define SLAYINGDEMONS_ACTION_H

#include <SFML/System/String.hpp>
#include "Fighter.h"
#include "Word.h"

namespace sd {
    class Action : public Word{
    private:
        Stats* stats;

    public:
        Action();
        ~Action();

        void LoadFrom(sf::String source);
        void Set(Stats* _stats);

        sd::Stats* GetStats();
    };
}

#endif //SLAYINGDEMONS_ACTION_H
