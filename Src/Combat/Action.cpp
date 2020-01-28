//
// Created by christian.heusser on 28.11.2019.
//

#include "Action.h"
#include <iostream>
#include <utility>

sd::Action::Action() {
    stats_ = std::make_shared<Stats>();
    set_stats({0, 0, 0, 0, 0, 0, 0, 0});
}

void sd::Action::load_from(std::string source) {

}

void sd::Action::set_stats(const sd::Stats& stats) {
    *stats_ = stats;
}

Sp<sd::Stats> sd::Action::get_stats() {
    return stats_;
}

void sd::Action::set_name(std::string name) {
    name_ = std::move(name);
}

std::string sd::Action::get_name() {
    return name_;
}

sd::Word::Type sd::Action::get_type() {
    return ACTION;
}
