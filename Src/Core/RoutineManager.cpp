//
// Created by felix on 02.03.20.
//

#include "RoutineManager.h"

Up<sd::RoutineManager> sd::RoutineManager::instance_ = nullptr;

sd::RoutineManager &sd::RoutineManager::get()
{
    return *instance_;
}

sd::RoutineManager::RoutineManager()
{
    if (!instance_)
        instance_ = Up<RoutineManager>(this);
}

void sd::RoutineManager::start_routine(Sp<sd::Routine> new_routine)
{
    new_routine->start();
    active_routines_.emplace_back(std::move(new_routine));
}

void sd::RoutineManager::process()
{
    auto save_copy = active_routines_;
    
    for (const auto& routine : save_copy) {
        if (routine->process())
            continue;
        
        // remove routine if it is expired
        active_routines_.erase(std::remove(active_routines_.begin(), active_routines_.end(), routine));
    }
}


