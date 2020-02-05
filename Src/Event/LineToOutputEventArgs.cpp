//
// Created by christian.heusser on 08.01.2020.
//

#include "LineToOutputEventArgs.h"
#include <utility>

sd::LineToOutputEventArgs::LineToOutputEventArgs(std::string line)
    : line(std::move(line)) {
    this->type = EventArgs::Type::LINE_TO_OUTPUT;
}
