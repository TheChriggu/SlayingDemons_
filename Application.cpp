//
// Created by christian.heusser on 05.11.2019.
//

#include "Application.h"
#include <iostream>

Application::Application()
    :window(new sf::RenderWindow(sf::VideoMode(1920,1080), "MyGame"))
{
    window->setFramerateLimit(60);
}

Application::~Application() {
    delete window;
    window = 0;
}

void Application::initialize() {
    std::cout << "Start initialization.\n";





    std::cout << "Create button\n";
    button = new Button(sf::Vector2f(600.0f,540.0f), sf::Vector2f(1.0f,1.0f), [&]{clear();});



    background = new DisplayArea(sf::Vector2f(0.0,0.0), sf::Vector2f(1920,1080), sf::Color::Blue);
    textOutput = new TextOutput(sf::Vector2f(48.0,41.0), sf::Vector2f(1044,1008), sf::Color::Red);
    wordList = new DisplayArea(sf::Vector2f(39.0,605.0), sf::Vector2f(1059,445), sf::Color::Yellow);
    inputField = new DisplayArea(sf::Vector2f(55,977), sf::Vector2f(1025,63), sf::Color::Magenta);
    map = new DisplayArea(sf::Vector2f(1127.0,41.0), sf::Vector2f(761,558), sf::Color::Green);
    books = new DisplayArea(sf::Vector2f(1103.0,611.0), sf::Vector2f( 816,461), sf::Color::Cyan);

    std::cout << "End initialization\n";
}

bool Application::run() {


    if(!window->isOpen())
    {
        return false;
    }

    //Input detection
    sf::Event evt;
    while (window->pollEvent(evt))
    {
        if (evt.type == sf::Event::Closed)
        {
            window->close();
        }

        else if (evt.type == sf::Event::TextEntered)
        {
            sf::Uint32 input = evt.text.unicode;
            textOutput->addText(input);
        }
        else if(evt.type == sf::Event::KeyPressed)
        {
            if(evt.key.code == sf::Keyboard::Enter)
            {
                textOutput->enterPressed();
            }

        }
        else if (evt.type == sf::Event::MouseButtonPressed)
        {
            if (evt.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mousePos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
                if(button->isPositionOnButton(mousePos))
                {
                    button->down();
                }
            }
        }
        else if (evt.type == sf::Event::MouseButtonReleased)
        {
            if (evt.mouseButton.button == sf::Mouse::Left)
            {
                button->up();
            }
        }
    }

    //Update Components


    //Clear Window
    window->clear();

    //Draw Components
    background->drawTo(window);
    textOutput->drawTo(window);
    wordList->drawTo(window);
    inputField->drawTo(window);
    map->drawTo(window);
    books->drawTo(window);

    //button->drawTo(window);


    //display
    window->display();


    //end
    return true;


}

void Application::clear() {
    //text->setString("");
}
