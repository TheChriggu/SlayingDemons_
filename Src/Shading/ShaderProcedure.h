//
// Created by felix on 07.01.20.
//

#ifndef _SHADERPROCEDURE_H_
#define _SHADERPROCEDURE_H_


#include <SFML/Graphics/RenderWindow.hpp>
#include <functional>
#include <SFML/Graphics/Shader.hpp>
#include <Core/GlobalDefinitions.h>

namespace sd {
    class ShaderProcedure {
    protected:
        Sp<sf::Shader> shader_;

    public:
        explicit ShaderProcedure(Sp<sf::Shader> shader);

        virtual void process(sf::RenderTarget*, const sf::Drawable*) const = 0;
    };
}


#endif //_SHADERPROCEDURE_H_
