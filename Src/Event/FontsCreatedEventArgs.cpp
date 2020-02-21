//
// Created by christian.heusser on 04.02.2020.
//

#include "FontsCreatedEventArgs.h"
#include <utility>

sd::FontsCreatedEventArgs::FontsCreatedEventArgs(Wp<Font> fonts) {
    this->type = EventArgs::Type::FONTS_CREATED;
    this->fonts = std::move(fonts);
}