//
// Created by christian.heusser on 05.11.2019.
//

#include "Application.h"
#include <iostream>
//#include "SFML\Graphics.hpp"

Application::Application()
    :window(new sf::RenderWindow(sf::VideoMode(800,600), "MyGame"))
{
    window->setFramerateLimit(60);
}

Application::~Application() {
    delete window;
    window = 0;
}

void Application::initialize() {
    sf::Font* font = new sf::Font();
    if (!font->loadFromFile("../Resources/Fonts/comic.ttf"))
    {
        std::cout << "Could not load Font!\n";
        return;
    }

    text = new sf::Text();
    text->setFont(*font);
    text->setString("");
    text->setCharacterSize(24);
    text->setFillColor(sf::Color::Red);
}

bool Application::run() {


    if(!window->isOpen())
    {
        return false;
    }

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
            sf::String strg = text->getString();
            if(input == 8 && strg.getSize() > 0)
            {
                strg.erase(strg.getSize()-1,1);
            }
            else
            {
                strg += evt.text.unicode;
            }

            text->setString(strg);
        }
        else if(evt.type == sf::Event::KeyPressed)
        {
            if(evt.key.code == sf::Keyboard::Enter)
            {
                sf::String strg = text->getString();
                strg += "\n";
                text->setString(strg);
            }

        }
        else
        {

        }
    }

    //Input detection


    //Update Components


    //Clear Window
    window->clear();

    //Draw Components
    window->draw(*text);

    //display
    window->display();


    //end
    return true;


}
