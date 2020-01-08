//
// Created by christian.heusser on 08.01.2020.
//

#ifndef SLAYINGDEMONS_LINETOOUTPUTEVENTARGS_H
#define SLAYINGDEMONS_LINETOOUTPUTEVENTARGS_H
#include "EventArgs.h"
#include <iostream>


namespace sd {
    class LineToOutputEventArgs: public EventArgs {
    public:
        explicit LineToOutputEventArgs(std::string _line);

        std::string line;
    };
}

#endif //SLAYINGDEMONS_LINETOOUTPUTEVENTARGS_H
