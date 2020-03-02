//
// Created by christian.heusser on 15.01.2020.
//

#include "FightStartedEventArgs.h"
#include <utility>

sd::FightStartedEventArgs::FightStartedEventArgs(Wp<Fight> fight) {
    this->type = EventArgs::Type::FIGHT_STARTED;
    this->fight = std::move(fight);
}
