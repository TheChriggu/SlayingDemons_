//
// Created by christian.heusser on 10.12.2019.
//

#include "Room.h"

sd::Room::Room(sf::Vector2f _position, sf::Vector2f _size)
    :position(_position)
    ,size(_size)
{
    tilemap = new Tilemap(11,7,position,sf::Vector2u(64,64));

    int room[] =
            {
                    0,1,1,1,1,5,1,1,1,1,2,
                    4,5,5,5,5,5,5,5,5,5,6,
                    4,5,5,5,5,5,5,5,5,5,6,
                    5,5,5,5,5,5,5,5,5,5,5,
                    4,5,5,5,5,5,5,5,5,5,6,
                    4,5,5,5,5,5,5,5,5,5,6,
                    8,9,9,9,9,5,9,9,9,9,10
            };

    tilemap->SetLayout(room, 77);

    roomObjects.emplace_back(new SingleTileObject("Mushroom", 12, sf::Vector2i(3,4)));
    

    for(auto object : roomObjects)
    {
        object->PutOnTileMap(tilemap);
    }
}

sd::Room::~Room() {

}

void sd::Room::DrawTo(sf::RenderTarget *window) const {
    window->draw(*tilemap);
}

sf::Vector2f sd::Room::GetPosition() {
    return DrawableObject::GetPosition();
}

sf::Vector2f sd::Room::GetSize() {
    return DrawableObject::GetSize();
}

void sd::Room::Handle(sf::Event event) {

}
