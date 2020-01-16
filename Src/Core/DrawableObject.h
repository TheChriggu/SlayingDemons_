//
// Created by christian.heusser on 06.11.2019.
//

#ifndef UNTITLED_DISPLAYAREA_H
#define UNTITLED_DISPLAYAREA_H

#include "Core/GlobalDefinitions.h"
#include "Core/Manageable.h"
#include "SFML/Graphics.hpp"
#include "Shading/ShaderProcedure.h"

namespace sd {
    class DrawableObject : public Manageable {
    protected:
        std::string name_;
        sp<ShaderProcedure> shaderProcedure_;

    public:
        explicit DrawableObject(std::string name);
        ~DrawableObject() override = default;

        bool Setup() override;
        void Shutdown() override;

        virtual void DrawTo(sp<sf::RenderTarget> window) const = 0;

        void SetShaderProcedure(sp<ShaderProcedure> shaderProcedure);
        [[nodiscard]] sp<ShaderProcedure> GetShaderProcedure() const;

        [[nodiscard]] const std::string& GetName() const;
        // TODO(FK) Temp
        void SetName(const char*);

        virtual sf::Vector2f GetPosition() = 0;
        virtual sf::Vector2f GetSize() = 0;

        virtual void Handle(sf::Event event) = 0;
    };
}


#endif //UNTITLED_DISPLAYAREA_H
