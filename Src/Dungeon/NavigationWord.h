//
// Created by christian.heusser on 07.01.2020.
//

#ifndef _NAVIGATIONWORD_H_
#define _NAVIGATIONWORD_H_

#include "../Word.h"
#include <iostream>

namespace sd {
    class NavigationWord : public Word {
    private:
        std::string name_;

    public:
        NavigationWord() = default;
        ~NavigationWord() override = default;

        Type get_type() override;

        void set_name(std::string name);
        std::string get_name();

    };
}

#endif //_NAVIGATIONWORD_H_
