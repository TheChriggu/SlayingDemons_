//
// Created by christian.heusser on 28.11.2019.
//

#ifndef _ACTION_H_
#define _ACTION_H_

#include <SFML/System/String.hpp>
#include <Core/GlobalDefinitions.h>
#include "Fighter.h"
#include "Word.h"

namespace sd {
    class Action : public Word{
    private:
        Sp<Stats> stats_;
        std::string name_;

    public:
        Action();
        ~Action() override = default;

        void load_from(std::string source);
        void set_stats(const Stats& stats);
        void set_name(std::string name);

        Sp<sd::Stats> get_stats();
        std::string get_name();

        Type get_type() override;
    };
}

#endif //_ACTION_H_
