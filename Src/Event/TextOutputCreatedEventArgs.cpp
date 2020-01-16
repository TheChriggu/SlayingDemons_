//
// Created by felix on 07.01.20.
//

#include "TextOutputCreatedEventArgs.h"
#include <utility>

sd::TextOutputCreatedEventArgs::TextOutputCreatedEventArgs(Sp<TextOutput> output) {
    this->type = EventArgs::Type::TEXT_OUTPUT_CREATED;
    this->output = std::move(output);
}
