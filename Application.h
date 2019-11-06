//
// Created by christian.heusser on 05.11.2019.
//

#ifndef UNTITLED_APPLICATION_H
#define UNTITLED_APPLICATION_H
#include "SFML\Graphics.hpp"
#include "Button.h"


class Application {

    sf::RenderWindow* window;
    sf::Text* text;
    Button* button;

public:
    Application();
    ~Application();

    void initialize();
    bool run();

    void clear();



};


#endif //UNTITLED_APPLICATION_H
