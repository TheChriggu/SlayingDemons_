//
// Created by felix on 27.11.19.
//

#ifndef _USERINPUT_H_
#define _USERINPUT_H_


#include <SFML/Graphics/RenderWindow.hpp>

namespace sd {

    // TODO(FK)
    class UserInput {

        sf::RenderWindow* window_;

    public:
        static UserInput* instance;
        explicit UserInput(sf::RenderWindow* window);
        virtual ~UserInput();

        UserInput(UserInput const&) = delete;
        void operator=(UserInput const&) = delete;

        static UserInput* GetInstance();

        sf::Vector2f get_mouse_position();
    };
}


#endif //_USERINPUT_H_
