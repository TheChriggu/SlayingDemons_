//
// Created by christian.heusser on 21.02.2020.
//

#ifndef SLAYINGDEMONS_SETSTAGEEVENTARGS_H
#define SLAYINGDEMONS_SETSTAGEEVENTARGS_H

#include "EventArgs.h"
#include <iostream>


namespace sd {
    class SetStageEventArgs : public EventArgs{
    public:
        explicit SetStageEventArgs(int stage);
        ~SetStageEventArgs() override = default;

        int stage;
    };
}

#endif //SLAYINGDEMONS_SETSTAGEEVENTARGS_H
