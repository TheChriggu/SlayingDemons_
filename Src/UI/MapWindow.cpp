//
// Created by christian.heusser on 10.12.2019.
//

#include "MapWindow.h"


sd::MapWindow::MapWindow(sf::Vector2f _position, sf::Vector2f _size)
    : DrawableObject("map-window")
    ,position(_position)
    ,size(_size)
{
    backgroundTexture = new sf::Texture();
    backgroundTexture->loadFromFile("../Resources/Sprites/fantasy_map.png");

    backgroundSprite = new sf::Sprite();
    backgroundSprite->setTexture(*backgroundTexture);
    backgroundSprite->setPosition(position);

    currenttileMap = new Tilemap(11,7,position + sf::Vector2f(40,44),sf::Vector2u(64,64));

}

sd::MapWindow::~MapWindow() {
    delete backgroundTexture;
    backgroundTexture = nullptr;

    delete backgroundSprite;
    backgroundSprite = nullptr;

    delete currenttileMap;
    currenttileMap = nullptr;
}

void sd::MapWindow::DrawTo(sf::RenderTarget *window) const {
    window->draw(*backgroundSprite);

    currenttileMap->SetLayout(playerState->GetCurrentRoom()->GetLayout(),77);
    window->draw(*currenttileMap);
}

sf::Vector2f sd::MapWindow::GetPosition() {
    return position;
}

sf::Vector2f sd::MapWindow::GetSize() {
    return size;
}

void sd::MapWindow::Handle(sf::Event event) {
    //room->Handle(event);
}

sd::Room *sd::MapWindow::GetRoom() {
    //return room;
    std::cout << "dont call MapWindow.GetRoom()!!\n";
    return nullptr;
}

void sd::MapWindow::SetPlayerState(sd::PlayerState *_playerState) {
    playerState = _playerState;
}
