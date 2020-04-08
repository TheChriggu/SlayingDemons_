//
// Created by felix on 02.03.20.
//

#include "Routine.h"
#include <utility>

sd::Routine::Routine(std::function<void()> update_body, float duration, std::function<bool(Sp<Routine> this_routine)> expired_body)
    : update_body_(std::move(update_body))
    , duration_(duration)
    , expired_body_(std::move(expired_body))
{ }

bool sd::Routine::process()
{
    if (update_body_)
        update_body_();
    
    // if routine expired execute the on_finished function
    if (timer_.getElapsedTime().asSeconds() >= duration_) {
        if (expired_body_)

            if (expired_body_(shared_from_this())) {
                // if on_finished body returns true restart the routine by resetting the timer and send restart signal back to RoutineManager
                start();
                return Routine::restart;
            }
            else
            {
                return Routine::end;
            }
            
        else
            return Routine::end;
    } else {
        return Routine::progress;
    }
}

void sd::Routine::start()
{
    timer_.restart();
}

void sd::Routine::set_duration(float new_duration)
{
    duration_ = new_duration;
}

