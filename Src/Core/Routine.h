//
// Created by felix on 02.03.20.
//

#ifndef _ROUTINE_H_
#define _ROUTINE_H_

#include <sol/function.hpp>
#include <SFML/System/Clock.hpp>

namespace sd {
    class Routine {
        public:
        Routine(std::function<void()> body, float duration, std::function<void()> on_finished_body);
        virtual ~Routine() = default;
        
        void start();
        bool process();
    
        private:
        sf::Clock timer_;
        float duration_;
        
        std::function<void()> body_;
        std::function<void()> on_finished_body_;
    };
}

#endif //_ROUTINE_H_
