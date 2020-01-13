//
// Created by felix on 30.11.19.
//

#include "ScriptEngine.h"
#include "IO/FileInput.h"
#include <memory>

sd::ScriptEngine::ScriptEngine() {
    if (!instance) instance = this;
    /*scripts_.emplace_back(
            Script(R"(
                    function test()
                        print("Test")
                     end
            )"),
            Script(R"(
                    function blub()
                        print("blub")
                     end
            )")
    );*/
}

sd::ScriptEngine *sd::ScriptEngine::Get() {

    return instance;
}


void sd::ScriptEngine::AddScript(const boost::filesystem::path& url) {
    scripts_.emplace_back(new Script(
            reinterpret_cast<const char *>(url.filename().c_str()),
            (*FileInput::Load(url))
    ));
}


std::shared_ptr<Script> sd::ScriptEngine::GetScript(const std::string& name) const {

    for (const auto& script : scripts_) {
        if (script->GetName() == (name + ".lua")) {
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

sd::ScriptEngine* sd::ScriptEngine::instance = nullptr;


