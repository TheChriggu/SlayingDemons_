//
// Created by christian.heusser on 03.12.2019.
//

#include "Attack.h"
#include <iostream>
#include <utility>

sd::Attack::Attack(Sp<sd::Fighter> fighter, const Sp<sd::Modifier>& modifier, const Sp<sd::Action>& action)
    : fighter_(std::move(fighter))
    , modifier_(modifier)
    , action_(action)
    {
        Modifier mod = *modifier;
        Action act = *action;

    }

sd::Stats sd::Attack::get_stats() {
    Stats ret_val = modifier_->apply_to(action_->get_stats());
    ret_val = (fighter_->GetOffense()) * ret_val;
    return ret_val;
}

std::string sd::Attack::get_sentence_second_person() {
    
    std::string ret_val = "You attack with " + modifier_->get_name() + " " + action_->get_name() + ".";
    return ret_val;
}

std::string sd::Attack::get_sentence_third_person() {
    std::string ret_val = "Your enemy attacks you with " + modifier_->get_name() + " " + action_->get_name() + ".";
    return ret_val;
}







