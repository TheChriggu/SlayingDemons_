//
// Created by felix on 10.01.20.
//

#ifndef SLAYINGDEMONS_PLAYERSTATECREATEDEVENTARGS_H
#define SLAYINGDEMONS_PLAYERSTATECREATEDEVENTARGS_H

#include <PlayerState.h>
#include "EventArgs.h"
#include "Core/GlobalDefinitions.h"

namespace sd {
    class PlayerStateCreatedEventArgs : public EventArgs {
    public:
        explicit PlayerStateCreatedEventArgs(Sp<PlayerState> player_state);

        Sp<PlayerState> player_state;
    };
}


#endif //SLAYINGDEMONS_PLAYERSTATECREATEDEVENTARGS_H
