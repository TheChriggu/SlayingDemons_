//
// Created by felix on 02.03.20.
//

#ifndef _ROUTINEMANAGER_H_
#define _ROUTINEMANAGER_H_

#include <vector>
#include "GlobalDefinitions.h"
#include "Routine.h"

#define CREATE_ROUTINE_BODY(content) \
std::function<void()>( \
    [&]() { \
        content \
        } \
    ) \


namespace sd {
    class RoutineManager {
        public:
        
        static RoutineManager& get();
        
        RoutineManager();
        
        void start_routine(Sp<Routine> new_routine);
        void process();
    
        private:
        
        static Up<RoutineManager> instance_;
        
        std::vector<Sp<Routine>> active_routines_;
    };
}

#endif //_ROUTINEMANAGER_H_
