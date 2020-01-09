//
// Created by felix on 09.01.20.
//

#ifndef SLAYINGDEMONS_GLITCH_H
#define SLAYINGDEMONS_GLITCH_H


#include "ShaderProcedure.h"

namespace sd {
    class Glitch : public ShaderProcedure {

        sp<sf::Clock> clock_;

    public:
        explicit Glitch(sp<sf::Shader> glitchShader);
        virtual ~Glitch() = default;

        void Process(sf::RenderTarget* window, const sf::Drawable* drawable) const override;
    };
}


#endif //SLAYINGDEMONS_GLITCH_H
