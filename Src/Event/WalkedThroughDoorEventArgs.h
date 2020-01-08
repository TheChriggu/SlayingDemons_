//
// Created by christian.heusser on 08.01.2020.
//

#ifndef SLAYINGDEMONS_WALKEDTHROUGHDOOREVENTARGS_H
#define SLAYINGDEMONS_WALKEDTHROUGHDOOREVENTARGS_H
#include "EventArgs.h"
#include "../Dungeon/Door.h"

namespace sd {
    class WalkedThroughDoorEventArgs: public EventArgs {
    public:
        explicit WalkedThroughDoorEventArgs(Door* _door);

        Door* door;
    };
}

#endif //SLAYINGDEMONS_WALKEDTHROUGHDOOREVENTARGS_H
