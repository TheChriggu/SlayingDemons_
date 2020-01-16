//
// Created by felix on 09.01.20.
//

#ifndef _GLITCH_H_
#define _GLITCH_H_


#include "ShaderProcedure.h"

namespace sd {
    class Glitch : public ShaderProcedure {

        Sp<sf::Clock> clock_;

    public:
        explicit Glitch(Sp<sf::Shader> glitch_shader);
        virtual ~Glitch() = default;

        void process(sf::RenderTarget* window, const sf::Drawable* drawable) const override;
    };
}


#endif //_GLITCH_H_
