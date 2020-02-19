//
// Created by christian.heusser on 04.02.2020.
//

#ifndef SLAYINGDEMONS_FONT_H
#define SLAYINGDEMONS_FONT_H

#include "SFML/Graphics.hpp"
#include "Core/GlobalDefinitions.h"

namespace sd {
    class Font : public std::enable_shared_from_this<Font> {
    private:
        Sp<sf::Font> fantasy_font_;
        Sp<sf::Font> cyber_font_;
        Sp<sf::Font> code_font_;

    public:
        Font();

        ~Font();

        Sp<sf::Font> GetFont(std::string font);
        Sp<sf::Font> GetCurrentFont();
    };
}

#endif //SLAYINGDEMONS_FONT_H
