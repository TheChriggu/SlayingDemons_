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
                    8,9,9,9,9,9,9,9,9,9,10,
                    8,9,9,9,9,9,9,9,9,9,10,
                    9,9,9,9,9,9,9,9,9,9,9,
                    8,9,9,9,9,9,9,9,9,9,10,
                    8,9,9,9,9,9,9,9,9,9,10,
                    16,17,17,17,17,5,17,17,17,17,18
            };

    tilemap->SetLayout(room, 77);

    roomObjects.emplace_back(new SingleTileObject("Mushroom", 24, sf::Vector2i(3,4)));

    int castleLayout[] = {3,4,11,12};
    roomObjects.emplace_back(new MultiTileObject("Castle", castleLayout,sf::Vector2i(2,2),sf::Vector2i(5,3)));


    for(auto object : roomObjects)
    {
        object->PutOnTileMap(tilemap);
    }
}

sd::Room::~Room() {
    roomObjects.clear();
    delete(tilemap);
    tilemap = nullptr;
}

void sd::Room::DrawTo(sf::RenderTarget *window) const {
    window->draw(*tilemap);
}

sf::Vector2f sd::Room::GetPosition() {
    return position;
}

sf::Vector2f sd::Room::GetSize() {
    return size;
}

void sd::Room::Handle(sf::Event event) {

}

sf::String sd::Room::GetDescription() {
    if (roomObjects.size() == 0)
    {
        return "The room is empty.";
    }


    sf::String retVal = "Inside the room there is a";
    for(auto object : roomObjects)
    {
        retVal += " " + object->GetName() + ",";
    }

    retVal += ".";

    return retVal;



}
