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
    class Routine : public std::enable_shared_from_this<Routine> {
        public:
        Routine(std::function<void()> body, float duration, std::function<void(Sp<Routine>)> on_finished_body);
        virtual ~Routine() = default;
        
        void start();
        bool process();
        
        void set_duration(float new_duration);
    
        private:
        sf::Clock timer_;
        float duration_;
        
        std::function<void()> body_;
        std::function<void(Sp<Routine>)> on_finished_body_;
    };
}

#endif //_ROUTINE_H_
