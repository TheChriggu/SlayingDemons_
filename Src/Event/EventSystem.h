//
// Created by felix on 07.01.20.
//

#ifndef SLAYINGDEMONS_EVENTSYSTEM_H
#define SLAYINGDEMONS_EVENTSYSTEM_H

#include <memory>
#include <vector>
#include "Event/Subscriber.h"
#include "Event/EventArgs.h"

namespace sd {
    class EventSystem {
        static std::unique_ptr<sd::EventSystem> instance;

    public:
        static EventSystem& Get();

        EventSystem();
        virtual ~EventSystem() = default;
        EventSystem(const EventSystem&) = delete;
        void operator=(const EventSystem&) = delete;

        void Subscribe(std::shared_ptr<Subscriber> newSubscriber);
        void Trigger(std::shared_ptr<EventArgs> e) const;

    private:
        std::vector<std::shared_ptr<Subscriber>> subscriber_;
    };
}


#endif //SLAYINGDEMONS_EVENTSYSTEM_H
