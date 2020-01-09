//
// Created by felix on 09.01.20.
//

#ifndef SLAYINGDEMONS_WEAKGLITCH_H
#define SLAYINGDEMONS_WEAKGLITCH_H

#include "ShaderProcedure.h"

namespace sd {
    class WeakGlitch : public ShaderProcedure {

        sp<sf::Clock> clock_;

    public:
        explicit WeakGlitch(sf::Shader* glitchShader);
        virtual ~WeakGlitch() = default;

        void Process(sf::RenderTarget* window, const sf::Sprite* drawable) const override;
    };
}


#endif //SLAYINGDEMONS_WEAKGLITCH_H
