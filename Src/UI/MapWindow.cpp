//
// Created by christian.heusser on 10.12.2019.
//

#include "MapWindow.h"

sd::MapWindow::MapWindow(sf::Vector2f _position, sf::Vector2f _size)
    :position(_position)
    ,size(_size)
{
    backgroundTexture = new sf::Texture();
    backgroundTexture->loadFromFile("../Resources/Sprites/fantasy_map.png");

    backgroundSprite = new sf::Sprite();
    backgroundSprite->setTexture(*backgroundTexture);
    backgroundSprite->setPosition(position);

    room = new Room((position + sf::Vector2f(40,44)), (size - sf::Vector2f(96,96)));

}

sd::MapWindow::~MapWindow() {
    delete room;
    room = nullptr;

    delete backgroundTexture;
    backgroundTexture = nullptr;

    delete backgroundSprite;
    backgroundSprite = nullptr;

}

void sd::MapWindow::DrawTo(sf::RenderTarget *window) const {
    window->draw(*backgroundSprite);
    room->DrawTo(window);
}

sf::Vector2f sd::MapWindow::GetPosition() {
    return position;
}

sf::Vector2f sd::MapWindow::GetSize() {
    return size;
}

void sd::MapWindow::Handle(sf::Event event) {
    room->Handle(event);
}
