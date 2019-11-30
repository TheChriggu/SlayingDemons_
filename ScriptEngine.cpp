//
// Created by felix on 30.11.19.
//

#include "ScriptEngine.h"

sd::ScriptEngine::ScriptEngine() {
    engine_ = nullptr;
}

sd::ScriptEngine::~ScriptEngine() {
    Shutdown();
}

bool sd::ScriptEngine::Setup() {
    engine_ = new chaiscript::ChaiScript();

    return true;
}

void sd::ScriptEngine::Shutdown() {
    delete engine_;
    engine_ = nullptr;
}
