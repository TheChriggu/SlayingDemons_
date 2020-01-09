//
// Created by felix on 07.01.20.
//

#ifndef SLAYINGDEMONS_SHADERPROCEDURE_H
#define SLAYINGDEMONS_SHADERPROCEDURE_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <functional>
#include <SFML/Graphics/Shader.hpp>
#include <Core/GlobalDefinitions.h>

namespace sd {
    class ShaderProcedure {
    protected:
        sp<sf::Shader> shader_;

    public:
        explicit ShaderProcedure(sp<sf::Shader> shader);

        virtual void Process(sf::RenderTarget*, const sf::Drawable*) const = 0;
    };
}


#endif //SLAYINGDEMONS_SHADERPROCEDURE_H
