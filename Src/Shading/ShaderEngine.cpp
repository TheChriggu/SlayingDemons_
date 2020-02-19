//
// Created by felix on 07.01.20.
//

#include <SFML/Graphics/Shader.hpp>
#include "ShaderEngine.h"
#include "IO/FileInput.h"
#include "NoisyLinesWeak.h"
#include "NoisyLinesMedium.h"
#include "ScriptEngine/ScriptEngine.h"
#include "RGBOffsetWeak.h"
#include "RGBSplit.h"
#include "HorizontalZigZag.h"


sd::ShaderEngine::ShaderEngine(std::vector<Sp<DrawableObject>>& drawable_objects)
    : drawable_objects_(drawable_objects)
    {

    ScriptEngine::get().register_all ("set_noisy_lines_weak__on", &ShaderEngine::set_noisy_lines_weak__on, this);
    ScriptEngine::get().register_all ("set_noisy_lines_medium_on", &ShaderEngine::set_noisy_lines_medium_on, this);
    ScriptEngine::get().register_all ("set_rgb_offset_weak_on", &ShaderEngine::set_rgb_offset_weak_on, this);
    ScriptEngine::get().register_all ("set_rgb_split_on", &ShaderEngine::set_rgb_split_on, this);
    ScriptEngine::get().register_all ("set_horizontal_zigzag_on", &ShaderEngine::set_horizontal_zigzag_on, this);
    ScriptEngine::get().register_all ("cancel_all_procedures_on", &ShaderEngine::cancel_all_procedures_on, this);
}

void sd::ShaderEngine::setup_all_shader() {
    //auto script_engine = ScriptEngine::Get();
    //script_engine.RegisterAll("cancel_all_procedures_on", &ShaderEngine::, this);

    noisy_lines_weak_ = new sf::Shader();
    noisy_lines_medium_ = new sf::Shader();
    rgb_offset_weak_ = new sf::Shader();
    rgb_split_ = new sf::Shader();
    horizontal_zigzag_ = new sf::Shader();

    /*auto shaderContent = FileInput::Load(
            boost::filesystem::path("../Resources/Shaders/noisy_lines_weak.frag")
            );
    weakglitch->loadFromMemory(*shaderContent, sf::Shader::Type::Fragment);

    shaderContent = FileInput::Load(
            boost::filesystem::path("../Resources/Shaders/mainVertexShader.vert")
    );
    weakglitch->loadFromMemory(*shaderContent, sf::Shader::Type::Vertex);*/

    shader_procedures_.emplace_back(std::make_shared<NoisyLinesWeak>(Sp<sf::Shader>(noisy_lines_weak_)));
    shader_procedures_.emplace_back(std::make_shared<NoisyLinesMedium>(Sp<sf::Shader>(noisy_lines_medium_)));
    shader_procedures_.emplace_back(std::make_shared<RGBOffsetWeak>(Sp<sf::Shader>(rgb_offset_weak_)));
    shader_procedures_.emplace_back(std::make_shared<RGBSplit>(Sp<sf::Shader>(rgb_split_)));
    shader_procedures_.emplace_back(std::make_shared<HorizontalZigZag>(Sp<sf::Shader>(horizontal_zigzag_)));
}

void sd::ShaderEngine::add_drawable_object(Sp<sd::DrawableObject> object) {
    drawable_objects_.emplace_back(object);
}

void sd::ShaderEngine::set_noisy_lines_weak__on(std::string object_name) const {
    // TODO(FK): replace with proper solution

    for (const auto& object : drawable_objects_) {
        if (object->get_name () == object_name) {
            object->set_shader_procedure (shader_procedures_[0]);
        }
    }
}

void sd::ShaderEngine::set_noisy_lines_medium_on(std::string object_name) const {
    // TODO(FK): replace with proper solution

    for (const auto& object : drawable_objects_) {
        if (object->get_name () == object_name) {
            object->set_shader_procedure (shader_procedures_[1]);
        }
    }
}

void sd::ShaderEngine::set_rgb_offset_weak_on(std::string object_name) const {
    for (const auto& object : drawable_objects_) {
        if (object->get_name () == object_name) {
            object->set_shader_procedure (shader_procedures_[2]);
        }
    }
}

void sd::ShaderEngine::set_rgb_split_on(std::string object_name) const {
    for (const auto& object : drawable_objects_) {
        if (object->get_name () == object_name) {
            object->set_shader_procedure (shader_procedures_[3]);
        }
    }
}

void sd::ShaderEngine::set_horizontal_zigzag_on(std::string object_name) const {
    for (const auto& object : drawable_objects_) {
        if (object->get_name () == object_name) {
            object->set_shader_procedure (shader_procedures_[4]);
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









