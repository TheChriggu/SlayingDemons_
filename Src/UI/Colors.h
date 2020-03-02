//
// Created by christian.heusser on 02.03.2020.
//

#ifndef SLAYINGDEMONS_COLORS_H
#define SLAYINGDEMONS_COLORS_H

#include "../Event/Subscriber.h"
#include "SFML/Graphics.hpp"
#include "Core/GlobalDefinitions.h"

namespace sd {
    class Colors: public std::enable_shared_from_this<Colors>, public Subscriber {
    private:
        sf::Color current_color_;
        sf::Color current_input_color_;

    public:
        Colors();
        ~Colors();

        sf::Color GetCurrentColor();
        sf::Color GetCurrentInputColor();
    };
}

#endif //SLAYINGDEMONS_COLORS_H
