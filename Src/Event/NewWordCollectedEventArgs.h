//
// Created by christian.heusser on 07.01.2020.
//

#ifndef _NEWWORDCOLLECTEDEVENTARGS_H_
#define _NEWWORDCOLLECTEDEVENTARGS_H_

#include "EventArgs.h"
#include <iostream>

namespace sd {
    class NewWordCollectedEventArgs : public EventArgs{
    public:
        explicit NewWordCollectedEventArgs(const std::string& word);
        ~NewWordCollectedEventArgs() override = default;

        const std::string& word;
    };
}

#endif //_NEWWORDCOLLECTEDEVENTARGS_H_
