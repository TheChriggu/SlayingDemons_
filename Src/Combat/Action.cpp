//
// Created by christian.heusser on 28.11.2019.
//

#include "Action.h"
#include <iostream>

sd::Action::Action() {
    stats = new Stats();
    SetStats( {0,0,0,0,0,0,0,0,0});
}

sd::Action::~Action() {

}

void sd::Action::LoadFrom(sf::String source) {

}

void sd::Action::SetStats(sd::Stats _stats) {
    *stats = _stats;
}

sd::Stats *sd::Action::GetStats() {
    return stats;
}

void sd::Action::SetName(sf::String _name) {
    name = _name;
}

sf::String sd::Action::GetName() {
    return name;
}
