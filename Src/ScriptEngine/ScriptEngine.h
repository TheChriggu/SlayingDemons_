//
// Created by felix on 30.11.19.
//

#ifndef SLAYINGDEMONS_SCRIPTENGINE_H
#define SLAYINGDEMONS_SCRIPTENGINE_H

#include <memory>
#include <vector>
#include "sol/sol.hpp"
#include "boost/filesystem.hpp"
#include "Script.h"

namespace sd {
    class ScriptEngine {

        static sd::ScriptEngine* instance;

        std::vector<std::shared_ptr<Script>> scripts_;

    public:


        ScriptEngine();
        virtual ~ScriptEngine() = default;

        static ScriptEngine* Get();

        void AddScript(const boost::filesystem::path& url);

        template <typename... Args>
        void Broadcast(const char* function, Args&&... args) {

            /*for (const auto& script : scripts_) {
                script->Call(function, std::forward<Args>(args)...);
            }*/
        }


        std::shared_ptr<Script> GetScript(const std::string& name) const;

        template <typename... Args, typename Key>
        void RegisterAll(Key&& key, Args&&... args) {
            for (auto script : scripts_) {
                script->RegisterFunction(std::forward<Key>(key), std::forward<Args>(args)...);
            }
        }
    };
}


#endif //SLAYINGDEMONS_SCRIPTENGINE_H
