//
// Created by christian.heusser on 28.11.2019.
//

#include "Action.h"
#include <iostream>
#include <utility>

sd::Action::Action(std::vector<std::string> line)
    :name_(line[0])
    ,description_2nd_person(line[9])
    ,description_3rd_person(line[10])
    {
    stats_ = std::make_shared<Stats>();

    set_stats({stof(line[1]), stof(line[2]), stof(line[3]), stof(line[4]), stof(line[5]),
                       stof(line[6]), stof(line[7]), stof(line[8])});

}

void sd::Action::set_stats(const sd::Stats& stats) {
    *stats_ = stats;
}

Sp<sd::Stats> sd::Action::get_stats() {
    return stats_;
}

std::string sd::Action::get_name() {
    return name_;
}

sd::Word::Type sd::Action::get_type() {
    return ACTION;
}

std::string sd::Action::get_sentence_2nd_person() {
    return description_2nd_person;
}

std::string sd::Action::get_sentence_3rd_person() {
    return description_3rd_person;
}
