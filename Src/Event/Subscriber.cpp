//
// Created by felix on 07.01.20.
//

#include "Subscriber.h"
#include "EventSystem.h"
#include <iostream>

sd::Subscriber::Subscriber() {
    std::cout << "Constructor Subscriber \n" << std::endl;
    EventSystem::Get().Subscribe(std::shared_ptr<Subscriber>(this));
}

