//
// Created by christian.heusser on 28.11.2019.
//

#ifndef _ACTION_H_
#define _ACTION_H_

#include <SFML/System/String.hpp>
#include <Core/GlobalDefinitions.h>
#include <vector>
#include "Fighter.h"
#include "Word.h"

namespace sd {
    class Action : public Word{
    private:
        Sp<Stats> stats_;
        std::string name_;
        std::string description_2nd_person;
        std::string description_3rd_person;

    public:
        Action(std::vector<std::string> line);
        ~Action() override = default;

        void set_stats(const Stats& stats);

        Sp<sd::Stats> get_stats();
        std::string get_name();
        std::string get_sentence_2nd_person();
        std::string get_sentence_3rd_person();

        Type get_type() override;
    };
}

#endif //_ACTION_H_
