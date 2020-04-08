//
// Created by felix on 02.03.20.
//

#ifndef _ROUTINEMANAGER_H_
#define _ROUTINEMANAGER_H_

#include <vector>
#include "GlobalDefinitions.h"
#include "Routine.h"

#define CREATE_UPDATE_BODY(content) \
std::function<void()>( \
    [&]() { \
        content \
        } \
    ) \

#define CREATE_EXPIRED_BODY(content) \
std::function<bool(Sp<Routine>)>( \
    [&](Sp<Routine> this_routine) { \
        content \
        } \
    ) \


namespace sd {
    class RoutineManager {
    public:
        
        static RoutineManager& get();
        
        RoutineManager();
        virtual ~RoutineManager() = default;
        // delete copy-constructor and assignment operator so singelton can not be copied
        RoutineManager(const RoutineManager&) = delete;
        void operator=(const RoutineManager&) = delete;
        
        void start_routine(Sp<Routine> new_routine);
        void process();
    
    private:
        static Up<RoutineManager> instance_;
        
        std::vector<Sp<Routine>> active_routines_;
    };
}

#endif //_ROUTINEMANAGER_H_
