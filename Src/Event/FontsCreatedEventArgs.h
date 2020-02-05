//
// Created by christian.heusser on 04.02.2020.
//

#ifndef SLAYINGDEMONS_FONTSCREATEDEVENTARGS_H
#define SLAYINGDEMONS_FONTSCREATEDEVENTARGS_H

#include "EventArgs.h"
#include <memory>
#include "UI/TextOutput.h"

namespace sd {
    class FontsCreatedEventArgs : public EventArgs {
    public:
        explicit FontsCreatedEventArgs(Font* fonts);
        ~FontsCreatedEventArgs() override = default;

        Font* fonts;
    };
}

#endif //SLAYINGDEMONS_FONTSCREATEDEVENTARGS_H
