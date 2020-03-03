//
// Created by christian.heusser on 06.02.2020.
//

#include <Core/RoutineManager.h>
#include "FunctionCollection.h"

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

bool sd::FunctionCollection::invoke_opened(std::function<void()> default_reaction)
{
    
    
    
    return false
}
bool sd::FunctionCollection::invoke_inspected(std::function<void()> default_reaction)
{
    sol::object result = be_inspected_signal_();
    
    if (result.is<sol::lua_nil_t>())
        return true;
    if (result.is<bool>())
        return result.as<bool>();
    
    
    if (result.is<float>())
    {
        RoutineManager::get().start_routine(
            std::make_shared<Routine>(
                nullptr,
                time,
                std::function<void(Sp<Routine>)>(
                    [this, default_reaction](Sp<Routine> this_routine) {
                        sol::object result = be_inspected_signal_();
                        
                        if (result.is<float>())
                        {
                            this_routine->set_duration(result.as<float>());
                            this_routine->start();
                        }
                        if (result.is<bool>())
                        {
                            if (result.as<bool>())
                                default_reaction();
                        }
                    }
                )
            )
        );
    }
    return false;
}
bool sd::FunctionCollection::invoke_fought(std::function<void()> default_reaction)
{
    return false;
}
bool sd::FunctionCollection::invoke_entered(std::function<void()> default_reaction)
{
    return false;
}
bool sd::FunctionCollection::invoke_destroyed(std::function<void()> default_reaction)
{
    return false;
}
