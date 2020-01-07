//
// Created by christian.heusser on 12.12.2019.
//all fault with the name of this class goes to Felix.
//

#ifndef SLAYINGDEMONS_PLAYERSTATE_H
#define SLAYINGDEMONS_PLAYERSTATE_H

#include "Dungeon/Floor.h"
#include "Dungeon/Room.h"
#include "Combat/Fight.h"
#include "PlayerVocabulary.h"

namespace sd {
    class PlayerState {
    private:
        Room* currentRoom;
        Fight* fight;
        Fighter* player;
        Floor* floor;
        PlayerVocabulary* playerVocabulary;

    public:
        PlayerState();
        ~PlayerState();

        Room* GetCurrentRoom();
        Fight* GetFight();
        bool IsFighting();

        void SetRoomAsCurrent(Room* room);
        void StartNewFight(Monster* enemy);
        void EndFight();

        PlayerVocabulary* GetPlayerVocabulary();

    };
}

#endif //SLAYINGDEMONS_PLAYERSTATE_H
