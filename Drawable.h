//
// Created by felix on 26.11.19.
//

#ifndef SLAYINGDEMONS_DRAWABLE_H
#define SLAYINGDEMONS_DRAWABLE_H

namespace sd {
    class Drawable {
    public:
        // declare virtual destructor to avoid potential memory leaks
        virtual ~Drawable() = default;

        virtual void Draw(sf::RenderWindow* window) const = 0;
    };
}

#endif //SLAYINGDEMONS_DRAWABLE_H
