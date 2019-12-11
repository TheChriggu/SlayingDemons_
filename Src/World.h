//
// Created by felix on 27.11.19.
//

#ifndef SLAYINGDEMONS_WORLD_H
#define SLAYINGDEMONS_WORLD_H

#include "Core/Manageable.h"

namespace sd {
    class World : public Manageable {
    public:
        World();
        virtual ~World();

        bool Setup() override;
        void Shutdown() override;
    };
}


#endif //SLAYINGDEMONS_WORLD_H