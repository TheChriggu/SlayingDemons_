//
// Created by christian.heusser on 05.11.2019.
//

#ifndef UNTITLED_APPLICATION_H
#define UNTITLED_APPLICATION_H
#include "SFML/Graphics.hpp"
#include "Button.h"
#include "DisplayArea.h"
#include "TextOutput.h"
#include <list>


class Application {

    sf::RenderWindow* window;
    Button* button;
    DisplayArea* background;
    TextOutput* textOutput;
    DisplayArea* wordList;
    DisplayArea* inputField;
    DisplayArea* map;
    DisplayArea* books;

public:
    Application();
    ~Application();

    void initialize();
    bool run();

    void clear();



};


#endif //UNTITLED_APPLICATION_H
