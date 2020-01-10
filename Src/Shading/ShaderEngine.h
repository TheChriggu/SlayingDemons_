//
// Created by felix on 07.01.20.
//

#ifndef SLAYINGDEMONS_SHADERENGINE_H
#define SLAYINGDEMONS_SHADERENGINE_H


#include <vector>
#include <Core/DrawableObject.h>
#include "Core/GlobalDefinitions.h"
#include "ShaderProcedure.h"

namespace sd {
    class ShaderEngine {

        std::vector<sp<ShaderProcedure>> shaderProcedures_;
        sf::Shader* weakglitch;
        sf::Shader* glitch;

        std::vector<DrawableObject*>* drawable_objects_;



    public:
        explicit ShaderEngine(std::vector<DrawableObject*>* drawable_objects);
        virtual ~ShaderEngine() = default;

        void SetupAllShader();

        void SetWeakglitchOn(std::string objectName) const;
        void SetGlitchOn(std::string objectName) const;
        void SetDemoGlitchOn(std::string objectName) const;

        void CancelAllProceduresOn(std::string objectName);
    };
}


#endif //SLAYINGDEMONS_SHADERENGINE_H
