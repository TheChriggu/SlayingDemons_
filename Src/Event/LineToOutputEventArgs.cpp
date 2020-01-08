//
// Created by christian.heusser on 08.01.2020.
//

#include "LineToOutputEventArgs.h"

sd::LineToOutputEventArgs::LineToOutputEventArgs(std::string _line) {
    this->type = EventArgs::Type::LineToOutput;
    this->line = _line;
}
