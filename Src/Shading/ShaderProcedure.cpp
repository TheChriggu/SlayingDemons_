//
// Created by felix on 07.01.20.
//

#include "ShaderProcedure.h"
#include <utility>

sd::ShaderProcedure::ShaderProcedure(Sp<sf::Shader> shader)
    : shader_(std::move(shader)) { }
