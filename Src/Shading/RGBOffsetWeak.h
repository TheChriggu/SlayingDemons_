//
// Created by christian.heusser on 19.02.2020.
//

#ifndef SLAYINGDEMONS_RGBOFFSETWEAK_H
#define SLAYINGDEMONS_RGBOFFSETWEAK_H


#include "ShaderProcedure.h"

namespace sd {
    class RGBOffsetWeak : public ShaderProcedure {

        Sp<sf::Clock> clock_;

    public:
        explicit RGBOffsetWeak(Sp<sf::Shader> glitch_shader);
        virtual ~RGBOffsetWeak() = default;

        void process(sf::RenderTarget* window, const sf::Drawable* drawable) const override;
    };
}

#endif //SLAYINGDEMONS_RGBOFFSETWEAK_H
