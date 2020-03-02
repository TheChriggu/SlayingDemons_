//
// Created by christian.heusser on 27.01.2020.
//

#ifndef _FORMAT_H_
#define _FORMAT_H_

#include <Core/GlobalDefinitions.h>
#include "SFML/Graphics.hpp"

namespace sd
{
    class Format {
    public:
        Sp<sf::Font> font_;
        unsigned int size_;
        sf::Color color_;
        unsigned int style_;
        std::string on_click_text_;
    };
}
#endif //_FORMAT_H_
