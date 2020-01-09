//
// Created by felix on 07.01.20.
//

#include <SFML/Graphics/Shader.hpp>
#include "ShaderEngine.h"
#include "IO/FileInput.h"
#include "WeakGlitch.h"
#include "Glitch.h"


sd::ShaderEngine::ShaderEngine(std::vector<DrawableObject *> &drawable_objects)
    : drawable_objects_(drawable_objects) { }

void sd::ShaderEngine::SetupAllShader() {
    weakglitch = new sf::Shader();
    glitch = new sf::Shader();

    /*auto shaderContent = FileInput::Load(
            boost::filesystem::path("../Resources/Shaders/weakglitch.frag")
            );
    weakglitch->loadFromMemory(*shaderContent, sf::Shader::Type::Fragment);

    shaderContent = FileInput::Load(
            boost::filesystem::path("../Resources/Shaders/glitch.vert")
    );
    weakglitch->loadFromMemory(*shaderContent, sf::Shader::Type::Vertex);*/

    shaderProcedures_.emplace_back(std::make_shared<WeakGlitch>(sp<sf::Shader>(weakglitch)));
    shaderProcedures_.emplace_back(std::make_shared<Glitch>(sp<sf::Shader>(glitch)));
}

void sd::ShaderEngine::SetWeakglitchOn(const std::string& objectName) const {
    // TODO(FK): replace with propper solution

    for (auto object : drawable_objects_) {
        if (object->GetName() == objectName) {
            object->SetShaderProcedure(shaderProcedures_[0]);
        }
    }
}

void sd::ShaderEngine::SetGlitchOn(const std::string& objectName) const {
    // TODO(FK): replace with propper solution

    for (auto object : drawable_objects_) {
        if (object->GetName() == objectName) {
            object->SetShaderProcedure(shaderProcedures_[1]);
        }
    }
}


