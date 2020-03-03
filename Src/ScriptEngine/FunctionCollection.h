//
// Created by christian.heusser on 06.02.2020.
//

#ifndef SLAYINGDEMONS_FUNCTIONCOLLECTION_H
#define SLAYINGDEMONS_FUNCTIONCOLLECTION_H

#include "sol/sol.hpp"

namespace sd {
    class FunctionCollection {
    
        sol::coroutine be_opened_signal_;
        sol::coroutine be_inspected_signal_;
        sol::coroutine be_fought_signal_;
        sol::coroutine be_entered_signal_;
        sol::coroutine be_destroyed_signal_;
        
    public:
        FunctionCollection(sol::coroutine be_opened_signal
                , sol::coroutine be_inspected_signal, sol::coroutine be_fought_signal
                , sol::coroutine be_entered_signal, sol::coroutine be_destroyed_signal);

        virtual ~FunctionCollection() = default;
        
        
        [[nodiscard]] bool is_opened_valid() const;
        [[nodiscard]] bool is_inspected_valid() const;
        [[nodiscard]] bool is_fought_valid() const;
        [[nodiscard]] bool is_entered_valid() const;
        [[nodiscard]] bool is_destroyed_valid() const;
        
        bool invoke_opened(std::function<void()> default_reaction);
        bool invoke_inspected(std::function<void()> default_reaction);
        bool invoke_fought(std::function<void()> default_reaction);
        bool invoke_entered(std::function<void()> default_reaction);
        bool invoke_destroyed(std::function<void()> default_reaction);

    };
}

#endif //SLAYINGDEMONS_FUNCTIONCOLLECTION_H
