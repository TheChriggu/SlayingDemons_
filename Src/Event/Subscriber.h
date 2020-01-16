//
// Created by felix on 06.01.20.
//

#ifndef _SUBSCRIBER_H_
#define _SUBSCRIBER_H_

#include <memory>
#include "Event/EventArgs.h"
#include "Core/GlobalDefinitions.h"

namespace sd {
    class Subscriber {
    public:
        Subscriber();
        // declare virtual destructor to avoid potential memory leaks
        virtual ~Subscriber() = default;

        virtual void handle(Sp<EventArgs> e) = 0;
    };
}


#endif //_SUBSCRIBER_H_
