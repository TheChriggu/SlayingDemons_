//
// Created by felix on 30.11.19.
//

#ifndef SLAYINGDEMONS_SCRIPT_H
#define SLAYINGDEMONS_SCRIPT_H

#include "sol/sol.hpp"


class Script {
public:
    Script();
    explicit Script(const char* content);
    virtual ~Script() = default;

    void SetConent(const char* content);
    void Call(const char* function) const;

private:
    std::unique_ptr<sol::state> state_;

};


#endif //SLAYINGDEMONS_SCRIPT_H
