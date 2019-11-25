//
// Created by christian.heusser on 05.11.2019.
//

#ifndef UNTITLED_APPLICATION_H
#define UNTITLED_APPLICATION_H
#include "SFML/Graphics.hpp"
#include "Button.h"
#include "DisplayArea.h"
#include "InputField.h"
#include "TextOutput.h"
#include "Tilemap.h"
#include <list>


class Application {

    sf::RenderWindow* window;
    Button* button;
    DisplayArea* background;
    TextOutput* textOutput;
    DisplayArea* wordList;
    InputField* inputField;
    DisplayArea* map;
    DisplayArea* books;
    Tilemap* tilemap;

public:
    Application();
    ~Application();

    void initialize();
    bool run();

    void clear();



};


#endif //UNTITLED_APPLICATION_H
