//
// Created by christian.heusser on 07.01.2020.
//

#ifndef SLAYINGDEMONS_NAVIGATIONWORD_H
#define SLAYINGDEMONS_NAVIGATIONWORD_H

#include "../Word.h"
#include <iostream>

namespace sd {
    class NavigationWord : public Word {
    private:
        std::string name;

    public:
        NavigationWord();
        ~NavigationWord() override;

        type GetType() override;

        void SetName(std::string _name);
        std::string GetName();

    };
}

#endif //SLAYINGDEMONS_NAVIGATIONWORD_H
