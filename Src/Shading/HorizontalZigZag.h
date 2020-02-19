//
// Created by christian.heusser on 19.02.2020.
//

#ifndef SLAYINGDEMONS_HORIZONTALZIGZAG_H
#define SLAYINGDEMONS_HORIZONTALZIGZAG_H

#include "ShaderProcedure.h"

namespace sd {
    class HorizontalZigZag : public ShaderProcedure{
        Sp<sf::Clock> clock_;

    public:
        explicit HorizontalZigZag(Sp<sf::Shader> glitch_shader);
        virtual ~HorizontalZigZag() = default;

        void process(sf::RenderTarget* window, const sf::Drawable* drawable) const override;
    };
}

#endif //SLAYINGDEMONS_HORIZONTALZIGZAG_H
