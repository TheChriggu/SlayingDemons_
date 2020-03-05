//
// Created by christian.heusser on 05.03.2020.
//

#ifndef SLAYINGDEMONS_CURSOR_H
#define SLAYINGDEMONS_CURSOR_H

#include "../Event/Subscriber.h"
#include "SFML/Graphics.hpp"
#include "../Core/GlobalDefinitions.h"

namespace sd {
    class Cursor : public Subscriber{
    private:
        Sp<sf::Texture> cursor_texture_;
        sf::Image cursor_image_;

        Sp<sf::Cursor> cursor_;

        bool has_changed;

    public:
        Cursor();
        ~Cursor() = default;

        Sp<sf::Cursor> get_cursor();

        bool check_on_mouse_cursor();
    };
}

#endif //SLAYINGDEMONS_CURSOR_H
