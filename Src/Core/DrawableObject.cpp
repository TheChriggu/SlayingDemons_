//
// Created by christian.heusser on 06.11.2019.
//

#include "DrawableObject.h"
#include <utility>
#include <iostream>

sd::DrawableObject::DrawableObject(std::string name)
    : name_(std::move(name))
    , shaderProcedure_(nullptr)
{ is_setup_ = false; }

sf::Vector2f sd::DrawableObject::GetPosition() {
    return sf::Vector2f(-1,-1);
}

sf::Vector2f sd::DrawableObject::GetSize() {
    return sf::Vector2f(-1,-1);
}

const std::string &sd::DrawableObject::GetName() const {
    return name_;
}

void sd::DrawableObject::SetShaderProcedure(sd::ShaderProcedure* shaderProcedure) {
    shaderProcedure_ = shaderProcedure;
}

sd::ShaderProcedure* sd::DrawableObject::GetShaderProcedure() const {
    return shaderProcedure_;
}

void sd::DrawableObject::SetName(const char *name) {
    name_ = name;
}

bool sd::DrawableObject::Setup() {
    return is_setup_ = true;
}

void sd::DrawableObject::Shutdown() {
    is_setup_ = false;
}


