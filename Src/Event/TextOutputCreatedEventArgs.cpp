//
// Created by felix on 07.01.20.
//

#include "TextOutputCreatedEventArgs.h"
#include <utility>

sd::TextOutputCreatedEventArgs::TextOutputCreatedEventArgs(std::shared_ptr<TextOutput> output) {
    this->type = EventArgs::Type::TextOutputCreated;
    this->output = std::move(output);
}
