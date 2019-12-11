//
// Created by felix on 30.11.19.
//

#ifndef SLAYINGDEMONS_SCRIPTENGINE_H
#define SLAYINGDEMONS_SCRIPTENGINE_H


#include "sol/sol.hpp"
#include "../Core/Manageable.h"
#include "Script.h"

namespace sd {
    class ScriptEngine {

        std::vector<Script> scripts_;

    public:
        ScriptEngine();
        virtual ~ScriptEngine() = default;

        void Broadcast(const char* function) const;
    };
}


#endif //SLAYINGDEMONS_SCRIPTENGINE_H
