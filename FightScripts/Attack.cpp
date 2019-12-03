//
// Created by christian.heusser on 03.12.2019.
//

#include "Attack.h"

sd::Attack::Attack(sd::Fighter *_fighter, sd::Modifier *_modifier, sd::Action *_action)
    :fighter(_fighter)
    ,modifier(_modifier)
    ,action(_action)
    {}

sd::Attack::~Attack() {
    fighter = nullptr;
    modifier = nullptr;
    action = nullptr;
}

sd::Stats sd::Attack::GetStats() {
    Stats retVal = modifier->ApplyTo(action->GetStats());
    retVal = (fighter->GetOffense())*retVal;
    return retVal;
}
