//
// Created by felix on 30.11.19.
//

#include "Script.h"

#include <memory>

Script::Script() {
    state_ = std::make_unique<sol::state>();
    state_->open_libraries(sol::lib::base);
}

Script::Script(const char *content) {
    state_ = std::make_unique<sol::state>();
    state_->open_libraries(sol::lib::base);

    state_->script(content);
}

void Script::SetConent(const char *content) {
    state_->script(content);
}

void Script::Call(const char *function) const {
    (*state_)[function]();
}
