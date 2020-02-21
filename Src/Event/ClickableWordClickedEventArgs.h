//
// Created by christian.heusser on 21.02.2020.
//

#ifndef SLAYINGDEMONS_CLICKABLEWORDCLICKEDEVENTARGS_H
#define SLAYINGDEMONS_CLICKABLEWORDCLICKEDEVENTARGS_H

#include "EventArgs.h"
#include <iostream>

namespace sd {
    class ClickableWordClickedEventArgs : public EventArgs {
            public:
            explicit ClickableWordClickedEventArgs(std::string word);
            ~ClickableWordClickedEventArgs() override = default;

            std::string word;
    };
}

#endif //SLAYINGDEMONS_CLICKABLEWORDCLICKEDEVENTARGS_H
