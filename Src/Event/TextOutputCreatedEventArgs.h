//
// Created by felix on 07.01.20.
//

#ifndef SLAYINGDEMONS_TEXTOUTPUTCREATEDEVENTARGS_H
#define SLAYINGDEMONS_TEXTOUTPUTCREATEDEVENTARGS_H


#include "EventArgs.h"
#include <memory>
#include "UI/TextOutput.h"

namespace sd {
    class TextOutputCreatedEventArgs : public EventArgs {
    public:
        explicit TextOutputCreatedEventArgs(Sp<TextOutput> output);

        Sp<TextOutput> output;
    };
}


#endif //SLAYINGDEMONS_TEXTOUTPUTCREATEDEVENTARGS_H
