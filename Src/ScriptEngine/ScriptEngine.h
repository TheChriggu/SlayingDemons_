//
// Created by felix on 30.11.19.
//

#ifndef SLAYINGDEMONS_SCRIPTENGINE_H
#define SLAYINGDEMONS_SCRIPTENGINE_H


#include "sol/sol.hpp"
#include "boost/filesystem.hpp"
#include "Script.h"

namespace sd {
    class ScriptEngine {

        static std::unique_ptr<sd::ScriptEngine> instance;

        std::vector<std::shared_ptr<Script>> scripts_;

    public:


        ScriptEngine();
        virtual ~ScriptEngine() = default;

        static ScriptEngine& Get();

        void AddScript(const boost::filesystem::path& url);

        void Broadcast(const char* function) const;
        std::shared_ptr<Script> GetScript(const std::string& name) const;
    };
}


#endif //SLAYINGDEMONS_SCRIPTENGINE_H
