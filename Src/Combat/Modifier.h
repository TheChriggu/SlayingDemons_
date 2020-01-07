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
        sf::String name;

    public:
        Modifier();
        ~Modifier() override;

        void LoadFrom(sf::String source);
        void SetStats(Stats _stats, StatwiseOperation _statwiseOperation);
        void SetName(sf::String _name);

        Stats ApplyTo(Stats* _stats);
        sf::String GetName();

        type GetType() override;
    };
}

#endif //SLAYINGDEMONS_MODIFIER_H
