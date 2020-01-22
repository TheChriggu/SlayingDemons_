//
// Created by felix on 07.01.20.
//

#include <SFML/Graphics/Shader.hpp>
#include "ShaderEngine.h"
#include "IO/FileInput.h"
#include "NoisyLinesWeak.h"
#include "NoisyLinesMedium.h"
#include "ScriptEngine/ScriptEngine.h"


sd::ShaderEngine::ShaderEngine(std::vector<Sp<DrawableObject>>& drawable_objects)
    : drawable_objects_(drawable_objects)
    {
    auto script_engine = ScriptEngine::Get();

      script_engine->register_all ("set_weak_glitch_on", &ShaderEngine::set_weak_glitch_on, this);
      script_engine->register_all ("set_glitch_on", &ShaderEngine::set_glitch_on, this);
      script_engine->register_all ("cancel_all_procedures_on", &ShaderEngine::cancel_all_procedures_on, this);
}

void sd::ShaderEngine::setup_all_shader() {
    //auto script_engine = ScriptEngine::Get();
    //script_engine.RegisterAll("cancel_all_procedures_on", &ShaderEngine::, this);

    weakglitch_ = new sf::Shader();
    glitch_ = new sf::Shader();

    /*auto shaderContent = FileInput::Load(
            boost::filesystem::path("../Resources/Shaders/noisy_lines_weak.frag")
            );
    weakglitch->loadFromMemory(*shaderContent, sf::Shader::Type::Fragment);

    shaderContent = FileInput::Load(
            boost::filesystem::path("../Resources/Shaders/mainVertexShader.vert")
    );
    weakglitch->loadFromMemory(*shaderContent, sf::Shader::Type::Vertex);*/

    shader_procedures_.emplace_back(std::make_shared<NoisyLinesWeak>(Sp<sf::Shader>(weakglitch_)));
    shader_procedures_.emplace_back(std::make_shared<NoisyLinesMedium>(Sp<sf::Shader>(glitch_)));
}

void sd::ShaderEngine::set_weak_glitch_on(std::string object_name) const {
    // TODO(FK): replace with proper solution

    for (const auto& object : drawable_objects_) {
        if (object->get_name () == object_name) {
            object->set_shader_procedure (shader_procedures_[0]);
        }
    }
}

void sd::ShaderEngine::set_glitch_on(std::string object_name) const {
    // TODO(FK): replace with proper solution

    for (const auto& object : drawable_objects_) {
        if (object->get_name () == object_name) {
            object->set_shader_procedure (shader_procedures_[1]);
        }
    }
}

void sd::ShaderEngine::cancel_all_procedures_on(std::string object_name) {

    for (const auto& object : drawable_objects_) {
        if (object->get_name () == object_name) {
            object->set_shader_procedure (nullptr);
        }
    }
}


