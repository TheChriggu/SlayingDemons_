//
// Created by felix on 02.03.20.
//

#ifndef _ROUTINE_H_
#define _ROUTINE_H_

#include <sol/function.hpp>
#include <SFML/System/Clock.hpp>
#include <memory>
#include "GlobalDefinitions.h"

namespace sd {
    // inherits from enable_shared_from_this to be able to call expired_body with shared this pointer
    class Routine : public std::enable_shared_from_this<Routine> {
    public:
        constexpr static bool progress = true;
        constexpr static bool restart = true;
        constexpr static bool end = false;
        
        Routine(std::function<void()> update_body, float duration, std::function<bool(Sp<Routine>)> expired_body);
        virtual ~Routine() = default;
        
        void start();
        bool process();
        
        void set_duration(float new_duration);
    
    private:
        sf::Clock timer_;
        float duration_;
        
        // gets executed on every process call
        std::function<void()> update_body_;
        // gets executed when Routine is expired
        std::function<bool(Sp<Routine>)> expired_body_;
    };
}

#endif //_ROUTINE_H_
