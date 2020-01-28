//
// Created by christian.heusser on 15.01.2020.
//

#ifndef _FIGHTSTARTEDEVENTARGS_H_
#define _FIGHTSTARTEDEVENTARGS_H_

#include "EventArgs.h"
#include "Combat/Fight.h"


namespace sd {
class FightStartedEventArgs : public EventArgs {
public:
    explicit FightStartedEventArgs(const Sp<Fight>& fight);
    ~FightStartedEventArgs() override = default;

    Sp<Fight> fight;
};
}


#endif //_FIGHTSTARTEDEVENTARGS_H_
