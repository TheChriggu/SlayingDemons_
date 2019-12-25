//
// Created by christian.heusser on 10.12.2019.
//

#ifndef SLAYINGDEMONS_SINGLETILEOBJECT_H
#define SLAYINGDEMONS_SINGLETILEOBJECT_H
#include "RoomObject.h"


namespace sd {
    class SingleTileObject : public RoomObject{
    protected:
        int spriteSheetIdx;
        std::string name;
        sf::Vector2i positionOnTileMap;

    public:
        SingleTileObject(std::string _name, int _spriteSheetIdx, sf::Vector2i _positionOnTileMap);
        ~SingleTileObject() override;

        virtual void PutOnLayout(int* layout, int width, int height) override;
        std::string GetName() override;
    };
}

#endif //SLAYINGDEMONS_SINGLETILEOBJECT_H
