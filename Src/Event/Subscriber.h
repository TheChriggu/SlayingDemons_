//
// Created by felix on 06.01.20.
//

#ifndef SLAYINGDEMONS_SUBSCRIBER_H
#define SLAYINGDEMONS_SUBSCRIBER_H

#include <memory>
#include "Event/EventArgs.h"

namespace sd {
    class Subscriber {
    public:
        Subscriber();
        // declare virtual destructor to avoid potential memory leaks
        virtual ~Subscriber() = default;

        virtual void Handle(EventArgs e) = 0;
    };
}


#endif //SLAYINGDEMONS_SUBSCRIBER_H
