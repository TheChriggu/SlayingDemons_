//
// Created by felix on 07.01.20.
//

#ifndef _TEXTOUTPUTCREATEDEVENTARGS_H_
#define _TEXTOUTPUTCREATEDEVENTARGS_H_


#include "EventArgs.h"
#include <memory>
#include "UI/TextOutput.h"

namespace sd {
    class TextOutputCreatedEventArgs : public EventArgs {
    public:
        explicit TextOutputCreatedEventArgs(Wp<TextOutput> output);
        ~TextOutputCreatedEventArgs() override = default;

        Wp<TextOutput> output;
    };
}


#endif //_TEXTOUTPUTCREATEDEVENTARGS_H_
