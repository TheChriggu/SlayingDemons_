//
// Created by christian.heusser on 08.01.2020.
//

#include "LineToOutputEventArgs.h"

sd::LineToOutputEventArgs::LineToOutputEventArgs(const std::string& line)
    : line(line) {
    this->type = EventArgs::Type::LINE_TO_OUTPUT;
}
