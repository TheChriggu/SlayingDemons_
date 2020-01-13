//
// Created by christian.heusser on 06.11.2019.
//

#ifndef UNTITLED_DISPLAYAREA_H
#define UNTITLED_DISPLAYAREA_H

#include "Core/GlobalDefinitions.h"
#include "Core/Manageable.h"
#include "SFML/Graphics.hpp"
#include "Drawable.h"
#include "Shading/ShaderProcedure.h"

namespace sd {
    class DrawableObject : public Manageable {
    protected:
        std::string name_;
        ShaderProcedure* shaderProcedure_;

    public:
        explicit DrawableObject(std::string name);
        virtual ~DrawableObject() = default;

        bool Setup() override;
        void Shutdown() override;

        virtual void DrawTo(sf::RenderTarget *window) const = 0;

        void SetShaderProcedure(ShaderProcedure* shaderProcedure);
        ShaderProcedure* GetShaderProcedure() const;
        const std::string& GetName() const;
        // TODO(FK) Temp
        void SetName(const char*);
        virtual sf::Vector2f GetPosition();
        virtual sf::Vector2f GetSize();

        virtual void Handle(sf::Event event) = 0;
    };
}


#endif //UNTITLED_DISPLAYAREA_H
