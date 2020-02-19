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
        sf::Shader* noisy_lines_weak_;
        sf::Shader* noisy_lines_medium_;
        sf::Shader* rgb_offset_weak_;

        std::vector<Sp<DrawableObject>>& drawable_objects_;



    public:
        explicit ShaderEngine(std::vector<Sp<DrawableObject>>& drawable_objects);
        virtual ~ShaderEngine() = default;

        void add_drawable_object(Sp<DrawableObject> object);

        void setup_all_shader();

        void set_noisy_lines_weak__on(std::string object_name) const;
        void set_noisy_lines_medium_on(std::string object_name) const;
        void set_rgb_offset_weak_on(std::string object_name) const;

        void cancel_all_procedures_on(std::string object_name);
    };
}


#endif //_SHADERENGINE_H_
