//
// Created by felix on 30.11.19.
//

#ifndef _SCRIPTENGINE_H_
#define _SCRIPTENGINE_H_

#include <memory>
#include <vector>
#include <Core/GlobalDefinitions.h>
#include "sol/sol.hpp"
#include "boost/filesystem.hpp"
#include "Script.h"

namespace sd {
    class ScriptEngine {

        static Up<sd::ScriptEngine> instance_;

        std::vector<std::shared_ptr<Script>> scripts_;

    public:


        ScriptEngine();
        virtual ~ScriptEngine() = default;

        static ScriptEngine& get();

        void add_script(const boost::filesystem::path& url);

        template <typename... Args>
        void broadcast(const std::string& function, Args&&... args) {

            for (const auto& script : scripts_) {
                script->call (function, std::forward<Args> (args)...);
            }
        }


        [[nodiscard]] std::shared_ptr<Script> get_script(const std::string& name) const;

        template <typename... Args, typename Key>
        void register_all(Key&& key, Args&&... args) {
            for (const auto& script : scripts_) {
                script->register_function (std::forward<Key> (key), std::forward<Args> (args)...);
            }
        }
    };
}


#endif //_SCRIPTENGINE_H_
