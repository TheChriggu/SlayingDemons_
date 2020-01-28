//
// Created by felix on 07.01.20.
//

#include "Subscriber.h"
#include "EventSystem.h"

sd::Subscriber::Subscriber() {
    EventSystem::get().subscribe(std::shared_ptr<Subscriber>(this));
}

