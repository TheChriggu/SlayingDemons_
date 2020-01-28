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

void sd::EventSystem::subscribe(const Sp<Subscriber>& new_subscriber) {
    subscriber_.emplace_back(new_subscriber);
}

void sd::EventSystem::trigger(const Sp<sd::EventArgs>& e) const {
    for (const auto& subscriber : subscriber_) {
        subscriber->handle (e);
    }
}
