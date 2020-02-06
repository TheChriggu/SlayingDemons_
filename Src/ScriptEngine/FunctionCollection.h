//
// Created by christian.heusser on 06.02.2020.
//

#ifndef SLAYINGDEMONS_FUNCTIONCOLLECTION_H
#define SLAYINGDEMONS_FUNCTIONCOLLECTION_H

#include "sol/sol.hpp"

namespace sd {
    class FunctionCollection {
    public:
        sol::function be_interacted_with_signal_;
        sol::function be_opened_signal_;
        sol::function be_inspected_signal_;
        sol::function be_fought_signal_;
        sol::function be_entered_signal_;
        sol::function be_destroyed_signal_;

        FunctionCollection(sol::function be_interacted_with_signal, sol::function be_opened_signal
                , sol::function be_inspected_signal, sol::function be_fought_signal
                , sol::function be_entered_signal, sol::function be_destroyed_signal);

        virtual ~FunctionCollection() = default;

    };
}

#endif //SLAYINGDEMONS_FUNCTIONCOLLECTION_H
