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
    Stats retVal = modifier->ApplyTo(action->GetStats());
    retVal = (fighter->GetOffense())*retVal;
    return retVal;
}

sf::String sd::Attack::GetSentenceSecondPerson() {
    sf::String retVal = "You attack with " + modifier->GetName() + " " + action->GetName() + ".";
    return retVal;
}

sf::String sd::Attack::GetSentenceThirdPerson() {
    sf::String retVal = "Your enemy attacks you with " + modifier->GetName() + " " + action->GetName() + ".";
    return retVal;
}







