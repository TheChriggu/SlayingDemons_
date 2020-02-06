//
// Created by christian.heusser on 06.02.2020.
//

#include "FunctionCollection.h"

sd::FunctionCollection::FunctionCollection(sol::function be_interacted_with_signal, sol::function be_opened_signal,
                                           sol::function be_inspected_signal, sol::function be_fought_signal,
                                           sol::function be_entered_signal, sol::function be_destroyed_signal)
                                           : be_interacted_with_signal_(be_interacted_with_signal)
                                           , be_opened_signal_(be_opened_signal)
                                           , be_inspected_signal_(be_inspected_signal)
                                           , be_fought_signal_(be_fought_signal)
                                           , be_entered_signal_(be_entered_signal)
                                           , be_destroyed_signal_(be_destroyed_signal)
                                           {}
