//
// Created by christian.heusser on 06.11.2019.
//

#include "DrawableObject.h"

sd::DrawableObject::DrawableObject()
{
}

sd::DrawableObject::~DrawableObject() {
}

sf::Vector2f sd::DrawableObject::GetPosition() {
    return sf::Vector2f(-1,-1);
}

sf::Vector2f sd::DrawableObject::GetSize() {
    return sf::Vector2f(-1,-1);
}


