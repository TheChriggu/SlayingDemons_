//
// Created by christian.heusser on 15.01.2020.
//

#ifndef SLAYINGDEMONS_FIGHTSTARTEDEVENTARGS_H
#define SLAYINGDEMONS_FIGHTSTARTEDEVENTARGS_H
#include "EventArgs.h"
#include "../Combat/Fight.h"


namespace sd {
class FightStartedEventArgs : public EventArgs {
public:
    explicit FightStartedEventArgs(Fight* _fight);

    Fight* fight;
};
}


#endif //SLAYINGDEMONS_FIGHTSTARTEDEVENTARGS_H
