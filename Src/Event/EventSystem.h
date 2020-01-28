//
// Created by felix on 07.01.20.
//

#ifndef _EVENTSYSTEM_H_
#define _EVENTSYSTEM_H_

#include <memory>
#include <vector>
#include "Event/Subscriber.h"
#include "Event/EventArgs.h"

namespace sd {
    class EventSystem {
        static Up<sd::EventSystem> instance_;

    public:
        static EventSystem& get();

        EventSystem();
        virtual ~EventSystem() = default;
        EventSystem(const EventSystem&) = delete;
        void operator=(const EventSystem&) = delete;

        void subscribe(const Sp<Subscriber>& new_subscriber);
        void trigger(const Sp<EventArgs>& e) const;

    private:
        std::vector<Sp<Subscriber>> subscriber_;
    };
}


#endif //_EVENTSYSTEM_H_
