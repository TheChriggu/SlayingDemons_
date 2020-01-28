//
// Created by christian.heusser on 28.11.2019.
//

#ifndef _MODIFIER_H_
#define _MODIFIER_H_

#include <SFML/System/String.hpp>
#include <Core/GlobalDefinitions.h>
#include "Fighter.h"
#include "Word.h"

namespace sd {
    class Modifier : public Word{
    private:
        Sp<Stats> stats_;
        Sp<StatwiseOperation> statwise_operation_;
        std::string name_;

    public:
        Modifier();
        ~Modifier() override = default;

        void load_from(std::string source);
        void set_stats(Stats stats, StatwiseOperation statwise_operation);
        void set_name(const std::string& name);

        Stats apply_to(const Sp<Stats>& stats);
        std::string get_name();

        Type get_type() override;
    };
}

#endif //_MODIFIER_H_
