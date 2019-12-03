//
// Created by christian.heusser on 03.12.2019.
//

#include "Attack.h"
#include <iostream>

sd::Attack::Attack(sd::Fighter *_fighter, sd::Modifier *_modifier, sd::Action *_action)
    :fighter(_fighter)
    ,modifier(_modifier)
    ,action(_action)
    {
        Modifier mod = *_modifier;
        Action act = *_action;

    }

sd::Attack::~Attack() {
    fighter = nullptr;
    modifier = nullptr;
    action = nullptr;
}

sd::Stats sd::Attack::GetStats() {
    std::cout << "get fighter stats\n";
    std::cout << "apply modifier to action\n";
    Stats retVal = modifier->ApplyTo(action->GetStats());
    std::cout << "multiply by offense\n";
    retVal = (fighter->GetOffense())*retVal;
    return retVal;
}
