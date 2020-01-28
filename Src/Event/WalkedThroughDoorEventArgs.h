//
// Created by christian.heusser on 08.01.2020.
//

#ifndef _WALKEDTHROUGHDOOREVENTARGS_H_
#define _WALKEDTHROUGHDOOREVENTARGS_H_

#include "EventArgs.h"
#include "Dungeon/Door.h"

namespace sd {
    class WalkedThroughDoorEventArgs: public EventArgs {
    public:
        explicit WalkedThroughDoorEventArgs(Sp<Door> door);
        ~WalkedThroughDoorEventArgs() override = default;

        Sp<Door> door;
    };
}

#endif //_WALKEDTHROUGHDOOREVENTARGS_H_
