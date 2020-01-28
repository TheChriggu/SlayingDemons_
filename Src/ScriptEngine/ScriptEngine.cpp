//
// Created by felix on 30.11.19.
//

#include "ScriptEngine.h"
#include "IO/FileInput.h"
#include <memory>

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



/*bool sd::ScriptEngine::Setup() {
    //sol::state _state;
    engine_ = new sol::state;

    engine_->open_libraries(sol::lib::base);

    engine_->script_file("../Resources/Scripts/test.lua");

    //sol::function func = (*engine_)["do_smth"];
    //func();
    (*engine_)["do_smth"]();
    //std::function<int()> better_func = func;
    //int var = better_func();

    sol::optional<bool> config = (*engine_)["config"]["fullscreen"];
    //config = (*engine_)["config"]["blub"];

    if(config) {
        std::cout << "script: " << typeof(true) << std::endl;
    }


    return true;
}*/

Up<sd::ScriptEngine> sd::ScriptEngine::instance_ = nullptr;


