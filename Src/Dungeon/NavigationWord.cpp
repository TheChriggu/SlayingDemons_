//
// Created by christian.heusser on 07.01.2020.
//

#include "NavigationWord.h"
#include <utility>

sd::Word::Type sd::NavigationWord::get_type() {
    return Type::COMMAND;
}

void sd::NavigationWord::set_name(std::string name) {
    name_ = std::move(name);
}

std::string sd::NavigationWord::get_name() {
    return name_;
}


