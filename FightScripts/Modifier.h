//
// Created by christian.heusser on 28.11.2019.
//

#ifndef SLAYINGDEMONS_MODIFIER_H
#define SLAYINGDEMONS_MODIFIER_H

#include <SFML/System/String.hpp>
#include "Fighter.h"
#include "Word.h"

namespace sd {
    class Modifier : public Word{
    private:
        Stats* stats;
        StatwiseOperation* statwiseOperation;

    public:
        Modifier();
        ~Modifier();

        void LoadFrom(sf::String source);
        void Set(Stats* _stats, StatwiseOperation* _statwiseOperation);

        Stats ApplyTo(Stats* _stats);
    };
}

#endif //SLAYINGDEMONS_MODIFIER_H
