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
        explicit FontsCreatedEventArgs(Wp<Font> fonts);
        ~FontsCreatedEventArgs() override = default;

        Wp<Font> fonts;
    };
}

#endif //SLAYINGDEMONS_FONTSCREATEDEVENTARGS_H
