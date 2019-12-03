//
// Created by christian.heusser on 28.11.2019.
//

#include "Action.h"
#include <iostream>
sd::Action::Action() {
    stats = new Stats();
    Set( {0,0,0,0,0,0,0,0,0});
}

sd::Action::~Action() {

}

void sd::Action::LoadFrom(sf::String source) {

}

void sd::Action::Set(sd::Stats _stats) {
    *stats = _stats;
}

sd::Stats *sd::Action::GetStats() {
    return stats;
}
