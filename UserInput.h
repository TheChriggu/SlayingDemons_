//
// Created by felix on 27.11.19.
//

#ifndef SLAYINGDEMONS_USERINPUT_H
#define SLAYINGDEMONS_USERINPUT_H


#include <SFML/Graphics/RenderWindow.hpp>

namespace sd {



    class UserInput {

        sf::RenderWindow* window_;


    public:
        static UserInput* instance;
        UserInput(sf::RenderWindow* window);
        virtual ~UserInput();

        UserInput(UserInput const&) = delete;
        void operator=(UserInput const&) = delete;

        static UserInput* GetInstance();

        sf::Vector2i GetMousePosition();
    };


}


#endif //SLAYINGDEMONS_USERINPUT_H
