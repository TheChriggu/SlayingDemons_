//
// Created by christian.heusser on 19.02.2020.
//

#ifndef SLAYINGDEMONS_GLOWINGPULSE_H
#define SLAYINGDEMONS_GLOWINGPULSE_H

#include "ShaderProcedure.h"
#include "SFML/Graphics.hpp"
#include <iostream>

namespace sd {
    class GlowingPulse : public ShaderProcedure{
        sf::Vector2f screen_size_;

        Sp<sf::Shader> greyscale_shader_;
        Sp<sf::Shader> blur_shader_;
        Sp<sf::Shader> average_shader_;
        Sp<sf::Clock> clock_;

        Sp<sf::RenderTexture> rendered_tex_;
        Sp<sf::RenderTexture> rendered_tex_2_;
        Sp<sf::Sprite> rendered_sprite_;
        Sp<sf::Sprite> rendered_sprite_2_;

    public:
        explicit GlowingPulse(Sp<sf::Shader> glitch_shader);
        virtual ~GlowingPulse() = default;

        void process(sf::RenderTarget* window, const sf::Drawable* drawable) const override;
    };
}

#endif //SLAYINGDEMONS_GLOWINGPULSE_H
