//
// Created by christian.heusser on 10.12.2019.
//

#ifndef SLAYINGDEMONS_ROOM_H
#define SLAYINGDEMONS_ROOM_H
#include "Tilemap.h"
#include "Core/DrawableObject.h"

namespace sd {
    class Room: public DrawableObject  {
    private:
        sf::Vector2f position;
        sf::Vector2f size;
        //int room[];

        Tilemap* tilemap;

    public:
        Room(sf::Vector2f _position, sf::Vector2f _size);
        ~Room() override;

        void DrawTo(sf::RenderTarget* window) const override;

        sf::Vector2f GetPosition() override;
        sf::Vector2f GetSize() override;

        void Handle(sf::Event event) override;
    };
}

#endif //SLAYINGDEMONS_ROOM_H
