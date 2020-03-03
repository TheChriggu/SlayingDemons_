//
// Created by christian.heusser on 06.02.2020.
//

#include <Core/RoutineManager.h>
#include "FunctionCollection.h"
#include "ScriptEngine.h"

sd::FunctionCollection::FunctionCollection(sol::coroutine be_opened_signal,
                                           sol::coroutine be_inspected_signal, sol::coroutine be_fought_signal,
                                           sol::coroutine be_entered_signal, sol::coroutine be_destroyed_signal)
                                           : be_opened_signal_(std::move(be_opened_signal))
                                           , be_inspected_signal_(std::move(be_inspected_signal))
                                           , be_fought_signal_(std::move(be_fought_signal))
                                           , be_entered_signal_(std::move(be_entered_signal))
                                           , be_destroyed_signal_(std::move(be_destroyed_signal))
                                           {}
                                           
bool sd::FunctionCollection::is_opened_valid() const
{
    return be_opened_signal_.valid();
}
bool sd::FunctionCollection::is_inspected_valid() const
{
    return be_inspected_signal_.valid();
}
bool sd::FunctionCollection::is_fought_valid() const
{
    return be_fought_signal_.valid();
}
bool sd::FunctionCollection::is_entered_valid() const
{
    return be_entered_signal_.valid();
}
bool sd::FunctionCollection::is_destroyed_valid() const
{
    return be_destroyed_signal_.valid();
}

bool sd::FunctionCollection::invoke_opened()
{
    return invoke(be_opened_signal_);
}
bool sd::FunctionCollection::invoke_inspected()
{
    return invoke(be_inspected_signal_);
}
bool sd::FunctionCollection::invoke_fought()
{
    return invoke(be_fought_signal_);
}
bool sd::FunctionCollection::invoke_entered()
{
    return invoke(be_entered_signal_);
}
bool sd::FunctionCollection::invoke_destroyed()
{
    return invoke(be_destroyed_signal_);
}

bool sd::FunctionCollection::invoke(sol::coroutine& coroutine)
{
    sol::object result = coroutine();
    
    if (result.is<sol::lua_nil_t>())
        return true;
    if (result.is<bool>())
        return result.as<bool>();
    
    
    if (result.is<float>())
    {
        ScriptEngine::get().start_lua_callback_routine(coroutine, result.as<float>());
    }
    return false;
}
