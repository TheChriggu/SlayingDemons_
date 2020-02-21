//
// Created by felix on 09.01.20.
//

#ifndef _WEAKGLITCH_H_
#define _WEAKGLITCH_H_

#include "ShaderProcedure.h"

namespace sd {
    class NoisyLinesWeak : public ShaderProcedure {

        Sp<sf::Clock> clock_;

    public:
        explicit NoisyLinesWeak(Sp<sf::Shader> glitch_shader);
        virtual ~NoisyLinesWeak() = default;

        void process(sf::RenderTarget* window, const sf::Drawable* drawable) const override;
    };
}


#endif //_WEAKGLITCH_H_
