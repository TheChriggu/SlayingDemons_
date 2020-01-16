//
// Created by felix on 10.01.20.
//

#include "PlayerStateCreatedEventArgs.h"
#include <utility>

sd::PlayerStateCreatedEventArgs::PlayerStateCreatedEventArgs(Sp<sd::PlayerState> player_state)
    : player_state(std::move(player_state))
{
    type = EventArgs::Type::PLAYER_STATE_CREATED;
}
