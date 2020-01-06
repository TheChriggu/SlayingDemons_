//
// Created by felix on 30.11.19.
//

#ifndef SLAYINGDEMONS_SCRIPT_H
#define SLAYINGDEMONS_SCRIPT_H

#include "sol/sol.hpp"


class Script {
public:
    explicit Script(const char* name);
    Script(const char* name, const std::string& content);
    virtual ~Script() = default;

    void AddContent(const char* content);
    void Call(const char* function) const;

    const std::string& GetName() const;

    sol::optional<sol::table> GetTable(const char* name) const;

    template <typename T>
    T GetVar(const char* name) const {
        return (*state_)[name];
    }

private:
    std::unique_ptr<sol::state> state_;
    std::string name_;
};


#endif //SLAYINGDEMONS_SCRIPT_H
