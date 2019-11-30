//
// Created by felix on 30.11.19.
//

#ifndef SLAYINGDEMONS_SCRIPTENGINE_H
#define SLAYINGDEMONS_SCRIPTENGINE_H

#include "chaiscript/chaiscript.hpp"
#include "Manageable.h"

namespace sd {
    class ScriptEngine : public Manageable {
        chaiscript::ChaiScript* engine_;

    public:
        ScriptEngine();
        virtual ~ScriptEngine();

        bool Setup() override;
        void Shutdown() override;
    };
}


#endif //SLAYINGDEMONS_SCRIPTENGINE_H
