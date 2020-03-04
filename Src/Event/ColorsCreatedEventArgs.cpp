//
// Created by christian.heusser on 02.03.2020.
//

#include "ColorsCreatedEventArgs.h"

sd::ColorsCreatedEventArgs::ColorsCreatedEventArgs(Wp<sd::Colors> colors) {
    this->type = EventArgs::Type::COLORS_CREATED;
    this->colors = std::move(colors);
}
