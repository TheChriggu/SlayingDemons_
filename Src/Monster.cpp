//
// Created by christian.heusser on 03.12.2019.
//

#include "Monster.h"
#include <iostream>
#include <utility>

sd::Monster::Monster(std::string path_to_portrait, std::string alias, std::string gender, std::string name) {
    path_to_portrait_ = std::move(path_to_portrait);
    alias_ = alias;
    gender_ = gender;
    name_ = name;
}

std::string sd::Monster::get_action() {
    std::cout << "getting enemy_ action\n";
    int i = rand()%(actions_.size());
    std::string ret_val = actions_.at(i);
    return ret_val;
}

std::string sd::Monster::get_modifier() {
    int i = rand()%(modifiers_.size());

    return modifiers_.at(i);
}

void sd::Monster::add_action(const std::string& action) {
    actions_.emplace_back(action);
}

void sd::Monster::add_modifier(const std::string& modifier) {
    modifiers_.emplace_back(modifier);
}

std::string sd::Monster::get_path_to_portrait() {
    return path_to_portrait_;
}

std::string sd::Monster::get_alias() {
    return alias_;
}

std::string sd::Monster::get_gender() {
    return gender_;
}

std::string sd::Monster::get_name() {
    return name_;
}
