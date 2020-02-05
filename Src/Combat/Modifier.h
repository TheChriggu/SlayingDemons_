//
// Created by christian.heusser on 28.11.2019.
//

#ifndef _MODIFIER_H_
#define _MODIFIER_H_

#include <SFML/System/String.hpp>
#include <Core/GlobalDefinitions.h>
#include <vector>
#include "Fighter.h"
#include "Word.h"

namespace sd {
    class Modifier : public Word{
    private:
        Sp<Stats> stats_;
        Sp<StatwiseOperation> statwise_operation_;
        std::string name_;
        std::string adjective_;
        std::string adverbial_;
        std::string material_;

    public:
        Modifier(std::vector<std::string> line);
        ~Modifier() override = default;

        void set_stats(Stats stats, StatwiseOperation statwise_operation);

        Stats apply_to(const Sp<Stats>& stats);
        std::string get_name();

        Type get_type() override;

        std::string get_adjective();
        std::string get_adverbial();
        std::string get_material();
    };
}

#endif //_MODIFIER_H_
