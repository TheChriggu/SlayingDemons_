//
// Created by felix on 30.11.19.
//

#include "Script.h"
#include <memory>

Script::Script(const std::string& name) {
    state_ = std::make_unique<sol::state>();
    state_->open_libraries(sol::lib::base, sol::lib::coroutine, sol::lib::table);

    name_ = name;
    // insert helper functions
    state_->script(R"(function wait(seconds) coroutine.yield(seconds) end)");
}

Script::Script(const std::string& name, const std::string& content) {
    state_ = std::make_unique<sol::state>();
    state_->open_libraries(sol::lib::base, sol::lib::coroutine, sol::lib::table);

    name_ = name;
    // insert helper functions
    state_->script(R"(function wait(seconds) coroutine.yield(seconds) end)");
    state_->script(content);
}

void Script::add_content(const std::string& content) {
    state_->script(content);
}

const std::string &Script::get_name() const {
    return name_;
}

sol::optional<sol::table> Script::get_table(const std::string& name) const {
    return (*state_)[name];
}
