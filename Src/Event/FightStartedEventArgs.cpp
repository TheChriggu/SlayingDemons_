//
// Created by christian.heusser on 15.01.2020.
//

#include "FightStartedEventArgs.h"

sd::FightStartedEventArgs::FightStartedEventArgs(const Sp<Fight>& fight) {
    this->type = EventArgs::Type::FIGHT_STARTED;
    this->fight = fight;
}
