//
// Created by christian.heusser on 21.02.2020.
//

#include "SetStageEventArgs.h"

sd::SetStageEventArgs::SetStageEventArgs(int stage)
    : stage(std::move(stage)) {
    this->type = EventArgs::Type::SET_STAGE;
}

