//
// Created by christian.heusser on 07.01.2020.
//

#ifndef SLAYINGDEMONS_NEWWORDCOLLECTEDEVENTARGS_H
#define SLAYINGDEMONS_NEWWORDCOLLECTEDEVENTARGS_H
#include "EventArgs.h"
#include <iostream>

namespace sd {
    class NewWordCollectedEventArgs : public EventArgs{
    public:
        explicit NewWordCollectedEventArgs(std::string _word);

        std::string word;
    };
}

#endif //SLAYINGDEMONS_NEWWORDCOLLECTEDEVENTARGS_H
