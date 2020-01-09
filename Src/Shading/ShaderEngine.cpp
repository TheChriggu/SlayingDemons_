//
// Created by felix on 07.01.20.
//

#include <SFML/Graphics/Shader.hpp>
#include "ShaderEngine.h"
#include "IO/FileInput.h"
#include "WeakGlitch.h"
#include "Glitch.h"
#include "ScriptEngine/ScriptEngine.h"


sd::ShaderEngine::ShaderEngine(std::vector<DrawableObject *>* drawable_objects)
    : drawable_objects_(drawable_objects)
    {
    auto script_engine = ScriptEngine::Get();

    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
    //script_engine->Broadcast("update");
    script_engine->RegisterAll("set_weakglitch_on", &ShaderEngine::SetWeakglitchOn, this);
    script_engine->RegisterAll("set_glitch_on", &ShaderEngine::SetWeakglitchOn, this);
    script_engine->RegisterAll("cancel_all_procedures_on", &ShaderEngine::CancelAllProceduresOn, this);
}

void sd::ShaderEngine::SetupAllShader() {
    //auto script_engine = ScriptEngine::Get();
    //script_engine.RegisterAll("cancel_all_procedures_on", &ShaderEngine::, this);

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

void sd::ShaderEngine::SetWeakglitchOn(std::string objectName) const {
    // TODO(FK): replace with propper solution

    for (auto object : (*drawable_objects_)) {
        if (object->GetName() == objectName) {
            object->SetShaderProcedure(shaderProcedures_[0].get());
        }
    }
}

void sd::ShaderEngine::SetGlitchOn(std::string objectName) const {
    // TODO(FK): replace with propper solution

    for (auto object : (*drawable_objects_)) {
        if (object->GetName() == objectName) {
            object->SetShaderProcedure(shaderProcedures_[1].get());
        }
    }
}

void sd::ShaderEngine::CancelAllProceduresOn(std::string objectName) {
    std::cout << "##cancel " << objectName << std::endl;
    for (auto object : (*drawable_objects_)) {
        std::cout << "--object " << object->GetName() << std::endl;
        if (object->GetName() == objectName) {
            std::cout << "--cancel on " << object->GetName() << std::endl;
            object->SetShaderProcedure(nullptr);
        }
    }
}


