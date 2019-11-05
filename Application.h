//
// Created by christian.heusser on 05.11.2019.
//

#ifndef UNTITLED_APPLICATION_H
#define UNTITLED_APPLICATION_H
#include "SFML\Graphics.hpp"


class Application {

    sf::RenderWindow* window;
    sf::Text* text;

public:
    Application();
    ~Application();

    void initialize();
    bool run();



};


#endif //UNTITLED_APPLICATION_H
