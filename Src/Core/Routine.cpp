//
// Created by felix on 02.03.20.
//

#include "Routine.h"
#include <utility>

sd::Routine::Routine(std::function<void()> body, float duration, std::function<void(Sp<Routine> this_routine)> on_finished_body)
    : body_(std::move(body))
    , duration_(duration)
    , on_finished_body_(std::move(on_finished_body))
{ }

bool sd::Routine::process()
{
    if (body_)
        body_();
    
    if (timer_.getElapsedTime().asSeconds() >= duration_) {
        if (on_finished_body_)
            on_finished_body_(shared_from_this());
        
        return false;
    } else {
        return true;
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

