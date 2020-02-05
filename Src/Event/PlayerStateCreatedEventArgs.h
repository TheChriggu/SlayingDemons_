//
// Created by felix on 10.01.20.
//

#ifndef _PLAYERSTATECREATEDEVENTARGS_H_
#define _PLAYERSTATECREATEDEVENTARGS_H_

#include <PlayerState.h>
#include "EventArgs.h"
#include "Core/GlobalDefinitions.h"

namespace sd {
    class PlayerStateCreatedEventArgs : public EventArgs {
    public:
        explicit PlayerStateCreatedEventArgs(PlayerState* player_state);
        ~PlayerStateCreatedEventArgs() override = default;
        
        PlayerState* player_state;
    };
}


#endif //_PLAYERSTATECREATEDEVENTARGS_H_
