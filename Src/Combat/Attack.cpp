//
// Created by christian.heusser on 03.12.2019.
//

#include "Attack.h"
#include <iostream>
#include <utility>
#include <Monster.h>
#include <strtk.hpp>

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
    ret_val = (fighter_->get_offense()) * ret_val;
    return ret_val;
}

/*std::string sd::Attack::get_sentence_second_person(Sp<Monster> attacked_monster) {
    std::string retVal = action_ ->get_sentence_2nd_person();

    retVal += modifier_ ->get_adjective() + modifier_->get_adverbial() + modifier_->get_material();

    return retVal;
}

std::string sd::Attack::get_sentence_third_person(Sp<Monster> attacking_monster) {
    std::string retVal = action_ ->get_sentence_3rd_person();

    retVal += modifier_ ->get_adjective() + modifier_->get_adverbial() + modifier_->get_material();

    return retVal;
}*/

std::string sd::Attack::get_sentence(int perspective, Sp<Monster> monster)
{
    std::string retVal;
    if(perspective ==2)
    {
        retVal = action_ ->get_sentence_2nd_person();
    }
    else
    {
        retVal = action_ ->get_sentence_3rd_person();
    }

    retVal = substitute(retVal, "[monster]", monster->get_alias());
    retVal = substitute(retVal, "[adjective]", modifier_->get_adjective());
    retVal = substitute(retVal, "[adverbial]", modifier_->get_adverbial());
    retVal = substitute(retVal, "[material]", modifier_->get_material());

    std::string gender = monster->get_gender();
    if(gender == "male")
    {
        retVal = substitute(retVal, "[he]", "he");
        retVal = substitute(retVal, "[his]", "his");
        retVal = substitute(retVal, "[him]", "him");

    }
    else if(gender == "female")
    {
        retVal = substitute(retVal, "[he]", "she");
        retVal = substitute(retVal, "[his]", "her");
        retVal = substitute(retVal, "[him]", "her");
    } else
    {
        retVal = substitute(retVal, "[he]", "it");
        retVal = substitute(retVal, "[his]", "its");
        retVal = substitute(retVal, "[him]", "its");
    }

    retVal = substitute(retVal, "[a] a", "an a");
    retVal = substitute(retVal, "[a] e", "an e");
    retVal = substitute(retVal, "[a] i", "an i");
    retVal = substitute(retVal, "[a] o", "an o");
    retVal = substitute(retVal, "[a] u", "an u");

    retVal = substitute(retVal, "[a] A", "an A");
    retVal = substitute(retVal, "[a] E", "an E");
    retVal = substitute(retVal, "[a] I", "an I");
    retVal = substitute(retVal, "[a] O", "an O");
    retVal = substitute(retVal, "[a] U", "an U");


    return retVal;
}

std::string sd::Attack::substitute(std::string search_in, std::string search_for, std::string replace_with) {
    std::string retVal;
    strtk::replace_pattern(search_in, search_for, replace_with, retVal);
    return retVal;
}

std::string sd::Attack::get_attack_name() {
    return modifier_->get_name() + " " + action_->get_name();
}









