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

const std::string &sd::DrawableObject::GetName() const {
    return name_;
}

void sd::DrawableObject::SetShaderProcedure(sp<sd::ShaderProcedure> shaderProcedure) {
    shaderProcedure_ = std::move(shaderProcedure);
}

sp<sd::ShaderProcedure> sd::DrawableObject::GetShaderProcedure() const {
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


