//
// Created by christian.heusser on 08.01.2020.
//

#ifndef _LINETOOUTPUTEVENTARGS_H_
#define _LINETOOUTPUTEVENTARGS_H_

#include "EventArgs.h"
#include <iostream>


namespace sd {
    class LineToOutputEventArgs: public EventArgs {
    public:
        explicit LineToOutputEventArgs(std::string line);
        ~LineToOutputEventArgs() override = default;

        std::string line;
    };
}

#endif //_LINETOOUTPUTEVENTARGS_H_
