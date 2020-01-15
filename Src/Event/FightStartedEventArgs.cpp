//
// Created by christian.heusser on 15.01.2020.
//

#include "FightStartedEventArgs.h"

sd::FightStartedEventArgs::FightStartedEventArgs(Fight* _fight) {
    this->type = EventArgs::Type::FightStarted;
    this->fight = _fight;
}
