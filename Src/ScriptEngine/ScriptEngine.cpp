//
// Created by felix on 30.11.19.
//

#include "ScriptEngine.h"
#include "IO/FileInput.h"
#include <memory>
#include <Core/RoutineManager.h>

Up<sd::ScriptEngine> sd::ScriptEngine::instance_ = nullptr;

sd::ScriptEngine::ScriptEngine() {
    if (!instance_)
        instance_ = Up<ScriptEngine>(this);
}

sd::ScriptEngine& sd::ScriptEngine::get() {

    return *instance_;
}


void sd::ScriptEngine::add_script(const boost::filesystem::path& url) {
    scripts_.emplace_back(new Script(
            url.filename().string(),
            (*FileInput::load (url))
    ));
}


std::shared_ptr<Script> sd::ScriptEngine::get_script(const std::string& name) const {

    for (const auto& script : scripts_) {
        std::string strg = script->get_name ();
        if (strg == (name + ".lua")) {
            return script;
        }
    }

    return nullptr;
}

void sd::ScriptEngine::set_broadcast_locked(bool locked)
{
    broadcast_locked_ = locked;
}

void sd::ScriptEngine::start_lua_callback_routine(sol::coroutine& function, float time) const
{
    RoutineManager::get().start_routine(
        std::make_shared<Routine>(
            nullptr,
            time,
            CREATE_ROUTINE_BODY(
                sol::object result = function();
    
                if (result.is<float>())
                {
                    this_routine->set_duration(result.as<float>());
                    return Routine::restart;
                }
                return Routine::end;
            )
        )
    );
}
