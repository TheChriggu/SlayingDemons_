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
        
        bool broadcast_locked_ = true;

    public:


        ScriptEngine();
        virtual ~ScriptEngine() = default;

        static ScriptEngine& get();

        void add_script(const boost::filesystem::path& url);
        void set_broadcast_locked(bool locked);

        template <typename... Args>
        void broadcast(const std::string& function, Args&&... args) {

            if (broadcast_locked_) return;
            
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
    
        template <typename... Args>
        void register_all_timeable(int argument_count, float default_wait_time, const char* key, Args&&... args) {
            for (const auto& script : scripts_) {
                script->register_timeable_function(argument_count, default_wait_time, key, std::forward<Args>(args)...);
            }
        }
        
        void start_lua_callback_routine(sol::coroutine& function, float time) const;
    };
}


#endif //_SCRIPTENGINE_H_
