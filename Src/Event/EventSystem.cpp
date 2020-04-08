//
// Created by felix on 07.01.20.
//

#include "EventSystem.h"

std::unique_ptr<sd::EventSystem> sd::EventSystem::instance_ = nullptr;

sd::EventSystem::EventSystem() {
    if (!instance_)
        sd::EventSystem::instance_ = std::unique_ptr<EventSystem>(this);
}

sd::EventSystem &sd::EventSystem::get() {
    return *instance_;
}

void sd::EventSystem::subscribe(Wp<std::function<void(Sp<EventArgs>)>> new_handler) {
    handlers_.emplace_back(std::move(new_handler));
}

void sd::EventSystem::trigger(const Sp<sd::EventArgs>& e) {
    // copy subscriber list to prevent errors if the list gets appended while looping through it
    auto save_copy = handlers_;
    
    for (const auto& handler : save_copy) {
        if(!handler.expired()) {
            (*handler.lock())(e);
        }
    }
}
