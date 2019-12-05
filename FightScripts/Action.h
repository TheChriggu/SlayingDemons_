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
        sf::String name;

    public:
        Action();
        ~Action() override;

        void LoadFrom(sf::String source);
        void SetStats(Stats _stats);
        void SetName(sf::String _name);

        sd::Stats* GetStats();
        sf::String GetName();
    };
}

#endif //SLAYINGDEMONS_ACTION_H
