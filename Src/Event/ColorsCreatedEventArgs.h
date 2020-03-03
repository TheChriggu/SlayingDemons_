//
// Created by christian.heusser on 02.03.2020.
//

#ifndef SLAYINGDEMONS_COLORSCREATEDEVENTARGS_H
#define SLAYINGDEMONS_COLORSCREATEDEVENTARGS_H

#include "EventArgs.h"
#include <memory>
#include "UI/TextOutput.h"

namespace sd {
    class ColorsCreatedEventArgs : public EventArgs {
    public:
        explicit ColorsCreatedEventArgs(Wp<Colors> colors);

        ~ColorsCreatedEventArgs() override = default;

        Wp<Colors> colors;
    };
}

#endif //SLAYINGDEMONS_COLORSCREATEDEVENTARGS_H
