//
// Created by christian.heusser on 04.02.2020.
//

#include "FontsCreatedEventArgs.h"

sd::FontsCreatedEventArgs::FontsCreatedEventArgs(Sp<Font> fonts) {
    this->type = EventArgs::Type::FONTS_CREATED;
    this->fonts = std::move(fonts);
}