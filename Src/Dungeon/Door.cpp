//
// Created by christian.heusser on 12.12.2019.
//

#include <memory>
#include <Event/EventArgs.h>
#include <Event/EventSystem.h>
#include <Event/WalkedThroughDoorEventArgs.h>
#include <Event/LineToOutputEventArgs.h>
#include <ScriptEngine/ScriptEngine.h>
#include "Door.h"

sd::Door::Door(std::string _name,
               int _spriteSheetIdxOpen, int _spriteSheetIdxLocked, sf::Vector2i _positionOnTileMap, std::string _nextRoom)
        : SingleTileObject(_name, _spriteSheetIdxOpen, _positionOnTileMap)
        , nextRoom(_nextRoom)
        ,spriteSheetIdxOpen(_spriteSheetIdxOpen)
        ,spriteSheetIdxLocked(_spriteSheetIdxLocked)
        ,isLocked(false)
{

}

const std::string& sd::Door::GetConnectedRoom() const {
    return nextRoom;
}

sd::Door::~Door() {

}

void sd::Door::PutOnLayout(int *layout, int width, int height) {
    //TODO: make sure position is within width & height
    SingleTileObject::PutOnLayout(layout, width, height);
}

std::string sd::Door::GetName() {
    return SingleTileObject::GetName();
}

void sd::Door::BeInteractedWith() {
    if(isLocked)
    {
        std::shared_ptr<LineToOutputEventArgs> args;
        args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("This door is locked."));
        EventSystem::Get().Trigger(args);
    }

    else {
        std::shared_ptr<WalkedThroughDoorEventArgs> args;
        args = std::make_shared<WalkedThroughDoorEventArgs>(WalkedThroughDoorEventArgs(this));
        args->type = sd::EventArgs::Type::WALKED_THROUGH_DOOR;
        EventSystem::Get().Trigger(args);

        /*if (nextRoom) {
            ScriptEngine::Get ()->broadcast ("room_changed", nextRoom->is_last);
        }*/
    }
}

void sd::Door::SetLocked(bool lockState) {
    isLocked = lockState;
    if(isLocked)
    {
        spriteSheetIdx = spriteSheetIdxLocked;
    }
    else
    {
        spriteSheetIdx = spriteSheetIdxOpen;
    }

    std::shared_ptr<EventArgs> args;
    args = std::make_shared<EventArgs>(EventArgs());
    args->type = sd::EventArgs::Type::ROOM_LAYOUT_CHANGED;
    EventSystem::Get().Trigger(args);
}
