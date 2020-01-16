//
// Created by christian.heusser on 06.11.2019.
//

#ifndef _DRAWABLEOBJECT_H_
#define _DRAWABLEOBJECT_H_

#include "Core/GlobalDefinitions.h"
#include "Core/Manageable.h"
#include "SFML/Graphics.hpp"
#include "Shading/ShaderProcedure.h"

namespace sd {
    class DrawableObject : public Manageable {
    protected:
        std::string name_;
        Sp<ShaderProcedure> shader_procedure_;

    public:
        explicit DrawableObject(std::string name);
        ~DrawableObject() override = default;

        bool setup() override;
        void shutdown() override;

        virtual void draw_to(Sp<sf::RenderTarget> window) const = 0;

        void set_shader_procedure(Sp<ShaderProcedure> shader_procedure);
        [[nodiscard]] Sp<ShaderProcedure> get_shader_procedure() const;

        [[nodiscard]] const std::string& get_name() const;
        // TODO(FK) Temp
        void set_name(const char* name);

        virtual sf::Vector2f get_position() = 0;
        virtual sf::Vector2f get_size() = 0;

        virtual void handle(sf::Event event) = 0;
    };
}


#endif //_DRAWABLEOBJECT_H_
