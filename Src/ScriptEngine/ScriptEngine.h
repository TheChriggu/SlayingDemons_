//
// Created by felix on 30.11.19.
//

#ifndef SLAYINGDEMONS_SCRIPTENGINE_H
#define SLAYINGDEMONS_SCRIPTENGINE_H


#include "sol/sol.hpp"
#include <filesystem>
#include "Script.h"

namespace sd {
    class ScriptEngine {

        std::vector<std::shared_ptr<Script>> scripts_;

    public:
        ScriptEngine();
        virtual ~ScriptEngine() = default;

        void AddScript(const std::filesystem::path& url);

        void Broadcast(const char* function) const;
        std::shared_ptr<Script> GetScript(const std::string& name) const;
    };
}


#endif //SLAYINGDEMONS_SCRIPTENGINE_H
