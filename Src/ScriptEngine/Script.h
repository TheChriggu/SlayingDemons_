//
// Created by felix on 30.11.19.
//

#ifndef _SCRIPT_H_
#define _SCRIPT_H_

#include "sol/sol.hpp"
#include <memory>
#include <regex>
#include "UI/TextOutput.h"
#include "Core/RoutineManager.h"

namespace sd {
    class Script {
        public:
        explicit Script(const std::string& name);
        Script(const std::string& name, const std::string& content);
        virtual ~Script() = default;
        
        void add_content(const std::string& content);
        
        [[nodiscard]] const std::string& get_name() const;
        [[nodiscard]] sol::optional<sol::table> get_table(const std::string& name) const;
        
        
        template <typename... Args>
        bool call(const std::string& function, Args&&... args) {
            sol::coroutine func = (*state_)[function];
            
            if (func.valid())
            {
                sol::object result = func(std::forward<Args>(args)...);
    
                if (result.is<sol::lua_nil_t>())
                {
                    std::cout << "#~# no return" << std::endl;
                    return true;
                }
                if (result.is<bool>())
                    return result.as<bool>();
    
    
                if (result.is<float>())
                {
                    std::cout << "#~# start coroutine" << std::endl;
                    coroutine_cache.emplace_back(func);
                    start_lua_callback_routine(coroutine_cache.back(), result.as<float>());
                }
                return false;
            }
        }
        
        template <typename T>
        T get_var(const std::string& name) const {
            return (*state_)[name];
        }
        
        template <typename... Args, typename Key>
        void register_function(Key&& key, Args&&... args) {
            state_->set_function(std::forward<Key>(key), std::forward<Args>(args)...);
        }
        
        template <typename... Args>
        void register_timeable_function(int argument_count, float default_wait_time, const char* key, Args&&... args) {
            // create inter-function that yields and simulates a overloaded function
            std::string test = "function " + std::string(key) + "(...) " +
                               "local args = table.pack(...) " +
                               "local wait_time = 0 " +
                               std::string(key) + "_instant(args[1]) " +
                               "if #args > " + std::to_string(argument_count) + " then wait_time = args[2] " +
                               "else wait_time = " + std::to_string(default_wait_time) + " end " +
                               "coroutine.yield(wait_time) "
                               "end";
            
            state_->script(test);
            
            state_->set_function(std::string(key) + "_instant", std::forward<Args>(args)...);
        }
    
        template <typename... Args>
        void start_lua_callback_routine(sol::coroutine& function, float time, Args&&... args) const
        {
            RoutineManager::get().start_routine(
                std::make_shared<Routine>(
                    nullptr,
                    time,
                    std::function<bool(Sp<Routine>)>(
                        [&](Sp<Routine> this_routine) {
                            sol::object result = function(std::forward<Args>(args)...);
    
                            if (result.is<float>())
                            {
                                this_routine->set_duration(result.as<float>());
                                return Routine::restart;
                            }
                            return Routine::end;
                        }
                    )
                )
            );
        }
    
        
        
        private:
        std::unique_ptr<sol::state> state_;
        std::string name_;
        
        std::vector<sol::coroutine> coroutine_cache;
    };
}


#endif //_SCRIPT_H_
