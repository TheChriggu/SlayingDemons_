//
// Created by christian.heusser on 03.12.2019.
//

#ifndef _ATTACK_H_
#define _ATTACK_H_

#include "Fighter.h"
#include "Modifier.h"
#include "Action.h"

namespace sd
{
    class Attack {
    private:
        Sp<Fighter> fighter_;
        Sp<Modifier> modifier_;
        Sp<Action> action_;


    public:
        Attack(Sp<Fighter> fighter, const Sp<Modifier>& modifier, const Sp<Action>& action);
        virtual ~Attack() = default;

        Stats get_stats();

        std::string get_sentence_second_person();
        std::string get_sentence_third_person();

    };
}



#endif //_ATTACK_H_
