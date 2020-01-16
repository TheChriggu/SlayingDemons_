//
// Created by felix on 30.11.19.
//

#ifndef _SCRIPT_H_
#define _SCRIPT_H_

#include "sol/sol.hpp"
#include <memory>


class Script {
public:
    explicit Script(const char* name);
    Script(const char* name, const std::string& content);
    virtual ~Script() = default;

    void add_content(const char* content);
    template <typename... Args>
    void call(const char* function, Args&&... args) const {
        sol::function func = (*state_)[function];

        if (func.valid())
            func(std::forward<Args>(args)...);
    }


    const std::string& get_name() const;

    sol::optional<sol::table> get_table(const char* name) const;

    template <typename T>
    T get_var(const char* name) const {
        return (*state_)[name];
    }

    template <typename... Args, typename Key>
    void register_function(Key&& key, Args&&... args) {
        state_->set_function(std::forward<Key>(key), std::forward<Args>(args)...);
    }

private:
    std::unique_ptr<sol::state> state_;
    std::string name_;
};


#endif //_SCRIPT_H_
