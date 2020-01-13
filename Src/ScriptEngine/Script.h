//
// Created by felix on 30.11.19.
//

#ifndef SLAYINGDEMONS_SCRIPT_H
#define SLAYINGDEMONS_SCRIPT_H

#include "sol/sol.hpp"
#include <memory>


class Script {
public:
    explicit Script(const char* name);
    Script(const char* name, const std::string& content);
    virtual ~Script() = default;

    void AddContent(const char* content);
    template <typename... Args>
    void Call(const char* function, Args&&... args) const {
        sol::function func = (*state_)[function];

        if (func.valid())
            func(std::forward<Args>(args)...);
    }


    const std::string& GetName() const;

    sol::optional<sol::table> GetTable(const char* name) const;

    template <typename T>
    T GetVar(const char* name) const {
        return (*state_)[name];
    }

    template <typename... Args, typename Key>
    void RegisterFunction(Key&& key, Args&&... args) {
        state_->set_function(std::forward<Key>(key), std::forward<Args>(args)...);
    }

private:
    std::unique_ptr<sol::state> state_;
    std::string name_;
};


#endif //SLAYINGDEMONS_SCRIPT_H
