//
// Created by felix on 06.01.20.
//

#ifndef _SUBSCRIBER_H_
#define _SUBSCRIBER_H_

#include <memory>
#include <functional>
#include "Event/EventArgs.h"
#include "Core/GlobalDefinitions.h"

#define CREATE_EVENT_HANDLER(content) \
std::make_shared<std::function<void(Sp<EventArgs>)>>( \
    [&](const Sp<EventArgs>& e) { \
        content \
    } \
); \

#define REGISTER_EVENT_HANDLER() \
EventSystem::get().subscribe(Wp<std::function<void(Sp<EventArgs>)>>(event_handler_));

namespace sd {
    class Subscriber {
    public:
        Subscriber();
        // declare virtual destructor to avoid potential memory leaks
        virtual ~Subscriber() = default;
    
        protected:
        Sp<std::function<void(Sp<EventArgs>)>> event_handler_;
    };
}


#endif //_SUBSCRIBER_H_
