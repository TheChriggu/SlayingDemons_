//
// Created by felix on 07.01.20.
//

#include "Subscriber.h"
#include "EventSystem.h"
#include <iostream>

sd::Subscriber::Subscriber() {
    EventSystem::Get().Subscribe(std::shared_ptr<Subscriber>(this));
}

