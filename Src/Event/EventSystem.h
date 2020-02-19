//
// Created by felix on 07.01.20.
//

#ifndef _EVENTSYSTEM_H_
#define _EVENTSYSTEM_H_

#include <memory>
#include <vector>
#include <functional>
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

        void subscribe(Wp<std::function<void(Sp<EventArgs>)>> new_handler);
        void trigger(const Sp<EventArgs>& e);

    private:
        std::vector<Wp<std::function<void(Sp<EventArgs>)>>> handlers_;
    };
}


#endif //_EVENTSYSTEM_H_
