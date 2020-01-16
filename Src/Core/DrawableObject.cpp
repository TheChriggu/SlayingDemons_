//
// Created by christian.heusser on 06.11.2019.
//

#include "DrawableObject.h"
#include <utility>
#include <iostream>

sd::DrawableObject::DrawableObject(std::string name)
    : name_(std::move(name))
    , shader_procedure_(nullptr)
{ is_setup_ = false; }

const std::string &sd::DrawableObject::get_name() const {
    return name_;
}

void sd::DrawableObject::set_shader_procedure(Sp<sd::ShaderProcedure> shader_procedure) {
    shader_procedure_ = std::move(shader_procedure);
}

Sp<sd::ShaderProcedure> sd::DrawableObject::get_shader_procedure() const {
    return shader_procedure_;
}

void sd::DrawableObject::set_name(const char *name) {
    name_ = name;
}

bool sd::DrawableObject::setup() {
    return is_setup_ = true;
}

void sd::DrawableObject::shutdown() {
    is_setup_ = false;
}


