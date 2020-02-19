//
// Created by felix on 07.01.20.
//

#include "EventSystem.h"

sd::EventSystem::EventSystem() {
    if (!instance_)
        sd::EventSystem::instance_ = std::unique_ptr<EventSystem>(this);
}

std::unique_ptr<sd::EventSystem> sd::EventSystem::instance_ = nullptr;

sd::EventSystem &sd::EventSystem::get() {
    return *instance_;
}

void sd::EventSystem::subscribe(std::string id, Wp<std::function<void(Sp<EventArgs>)>> new_handler) {
    handlers_.emplace(id, new_handler);//.emplace_back(new_handler);
}

void sd::EventSystem::trigger(const Sp<sd::EventArgs>& e) {
    for (const auto& pair : handlers_) {
        auto handler = pair.second;
        if(!handler.expired()) {
            auto func = *handler.lock();
            if (!func)
                continue;
            func(e);
        }
    }
}
