//
// Created by christian.heusser on 21.02.2020.
//

#include "ClickableWordClickedEventArgs.h"

sd::ClickableWordClickedEventArgs::ClickableWordClickedEventArgs(std::string word) : word(std::move(word)) {
        this->type = EventArgs::Type::CLICKABLE_WORD_CLICKED;
}
