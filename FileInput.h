//
// Created by felix on 27.11.19.
//

#ifndef SLAYINGDEMONS_FILEINPUT_H
#define SLAYINGDEMONS_FILEINPUT_H

#include "Manageable.h"

namespace sd {
    class FileInput : public Manageable {
    public:
        FileInput();
        virtual ~FileInput();

        bool Setup() override;
        void Shutdown() override;
    };
}


#endif //SLAYINGDEMONS_FILEINPUT_H
