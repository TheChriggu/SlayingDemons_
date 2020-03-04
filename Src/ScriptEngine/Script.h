//
// Created by felix on 30.11.19.
//

#ifndef _SCRIPT_H_
#define _SCRIPT_H_

#include "sol/sol.hpp"
#include <memory>
#include <regex>
#include "UI/TextOutput.h"


class Script {
public:
    explicit Script(const std::string& name);
    Script(const std::string& name, const std::string& content);
    virtual ~Script() = default;
    
    void add_content(const std::string& content);
    
    [[nodiscard]] const std::string& get_name() const;
    [[nodiscard]] sol::optional<sol::table> get_table(const std::string& name) const;
    
    
    template <typename... Args>
    void call(const std::string& function, Args&&... args) const {
        sol::function func = (*state_)[function];
        
        if (func.valid())
            func(std::forward<Args>(args)...);
    }

    template <typename T>
    T get_var(const std::string& name) const {
        return (*state_)[name];
    }

    template <typename... Args, typename Key>
    void register_function(Key&& key, Args&&... args) {
        state_->set_function(std::forward<Key>(key), std::forward<Args>(args)...);
    }
    
    template <typename... Args>
    void register_timeable_function(int argument_count, float default_wait_time, const char* key, Args&&... args) {
        // create inter-function that yields and simulates a overloaded function
        std::string test = "function " + std::string(key) + "(...) " +
                           "local args = table.pack(...) " +
                           "local wait_time = 0 " +
                           std::string(key) + "_instant(args[1]) " +
                             "if #args > " + std::to_string(argument_count) + " then wait_time = args[2] " +
                             "else wait_time = " + std::to_string(default_wait_time) + " end " +
                           "coroutine.yield(wait_time) "
                           "end";
        
        state_->script(test);
        
        state_->set_function(std::string(key) + "_instant", std::forward<Args>(args)...);
    }

private:
    std::unique_ptr<sol::state> state_;
    std::string name_;
};


#endif //_SCRIPT_H_
