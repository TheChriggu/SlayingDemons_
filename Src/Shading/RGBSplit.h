//
// Created by christian.heusser on 19.02.2020.
//

#ifndef SLAYINGDEMONS_RGBSPLIT_H
#define SLAYINGDEMONS_RGBSPLIT_H

#include "ShaderProcedure.h"

namespace sd {
    class RGBSplit : public ShaderProcedure {
        Sp<sf::Clock> clock_;

    public:
        explicit RGBSplit(Sp<sf::Shader> glitch_shader);
        virtual ~RGBSplit() = default;

        void process(sf::RenderTarget* window, const sf::Drawable* drawable) const override;
    };
}

#endif //SLAYINGDEMONS_RGBSPLIT_H
