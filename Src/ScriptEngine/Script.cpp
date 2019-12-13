//
// Created by felix on 30.11.19.
//

#include "Script.h"

#include <memory>

Script::Script(const char* name) {
    state_ = std::make_unique<sol::state>();
    state_->open_libraries(sol::lib::base);

    name_ = name;
}

Script::Script(const char* name, const std::string& content) {
    state_ = std::make_unique<sol::state>();
    state_->open_libraries(sol::lib::base);

    name_ = name;
    state_->script(content);
}

void Script::SetConent(const char *content) {
    state_->script(content);
}

void Script::Call(const char *function) const {
    sol::function func = (*state_)[function];

    if (func.valid())
        func();
}

const std::string &Script::GetName() const {
    return name_;
}
