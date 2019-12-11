//
// Created by felix on 30.11.19.
//

#include "ScriptEngine.h"

sd::ScriptEngine::ScriptEngine() {
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


void sd::ScriptEngine::Broadcast(const char *function) const {
    for (const auto& script : scripts_) {
        script.Call(function);
    }
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
