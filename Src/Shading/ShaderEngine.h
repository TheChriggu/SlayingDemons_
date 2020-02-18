//
// Created by felix on 07.01.20.
//

#ifndef _SHADERENGINE_H_
#define _SHADERENGINE_H_


#include <vector>
#include <Core/DrawableObject.h>
#include "Core/GlobalDefinitions.h"
#include "ShaderProcedure.h"

namespace sd {
    class ShaderEngine {

        std::vector<Sp<ShaderProcedure>> shader_procedures_;
        sf::Shader* weakglitch_;
        sf::Shader* glitch_;

        std::vector<Sp<DrawableObject>>& drawable_objects_;



    public:
        explicit ShaderEngine(std::vector<Sp<DrawableObject>>& drawable_objects);
        virtual ~ShaderEngine() = default;

        void add_drawable_object(Sp<DrawableObject> object);

        void setup_all_shader();

        void set_weak_glitch_on(std::string object_name) const;
        void set_glitch_on(std::string object_name) const;

        void cancel_all_procedures_on(std::string object_name);
    };
}


#endif //_SHADERENGINE_H_
