//
// Created by felix on 30.11.19.
//

#ifndef SLAYINGDEMONS_SCRIPTENGINE_H
#define SLAYINGDEMONS_SCRIPTENGINE_H


#include "sol/sol.hpp"
#include "../Core/Manageable.h"

namespace sd {
    class ScriptEngine : public Manageable {
        sol::state* engine_;

    public:
        ScriptEngine();
        virtual ~ScriptEngine();

        bool Setup() override;
        void Shutdown() override;
    };
}


#endif //SLAYINGDEMONS_SCRIPTENGINE_H
