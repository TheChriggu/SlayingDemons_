//
// Created by felix on 07.01.20.
//

#include "EventSystem.h"

sd::EventSystem::EventSystem() {
    if (!instance) sd::EventSystem::instance = std::unique_ptr<EventSystem>(this);
}

std::unique_ptr<sd::EventSystem> sd::EventSystem::instance = nullptr;

sd::EventSystem &sd::EventSystem::Get() {
    return *instance;
}

void sd::EventSystem::Subscribe(std::shared_ptr<Subscriber> newSubscriber) {
    subscriber_.emplace_back(newSubscriber);
}

void sd::EventSystem::Trigger(std::shared_ptr<sd::EventArgs> e) const {
    for (auto subscriber : subscriber_) {
        subscriber->Handle(e);
    }
}
