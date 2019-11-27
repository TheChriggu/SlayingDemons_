//
// Created by christian.heusser on 05.11.2019.
//

#include "Application.h"
#include <iostream>

sd::Application::Application()
{
    window_ = nullptr;
}



bool sd::Application::Setup() {
    window_ = new sf::RenderWindow(sf::VideoMode(1920, 1080), "MyGame");
    window_->setFramerateLimit(60);

    std::cout << "Start initialization.\n";

    std::cout << "Create button\n";
    drawable_objects_.emplace_back(new Button(sf::Vector2f(1200.0f,500.0f), sf::Vector2f(1.0f,1.0f), [&]{clear();}));

    drawable_objects_.emplace_back(new DrawableObject(sf::Vector2f(0.0, 0.0), sf::Vector2f(1920, 1080)));
    drawable_objects_.emplace_back(new TextOutput(sf::Vector2f(48.0,41.0), sf::Vector2f(1044,1008), sf::Color::Red));
    drawable_objects_.emplace_back(new DrawableObject(sf::Vector2f(39.0, 605.0), sf::Vector2f(1059, 445)));
    drawable_objects_.emplace_back(new InputField(sf::Vector2f(55,977), sf::Vector2f(1025,63), sf::Color::Magenta));
    drawable_objects_.emplace_back(new DrawableObject(sf::Vector2f(1127.0, 41.0), sf::Vector2f(761, 558)));
    drawable_objects_.emplace_back(new DrawableObject(sf::Vector2f(1103.0, 611.0), sf::Vector2f(816, 461)));

    std::cout << "End initialization\n";

    return true;
}

void sd::Application::Shutdown() {
    delete window_;
    window_ = nullptr;
}

bool sd::Application::Run() {


    if(!window_->isOpen())
    {
        return false;
    }

    //Input detection
    sf::Event evt;
    while (window_->pollEvent(evt))
    {
        if (evt.type == sf::Event::Closed)
        {
            window_->close();
        }

        /*else if (evt.type == sf::Event::TextEntered)
        {
            sf::Uint32 input = evt.text.unicode;
            inputField->addText(input);
        }
        else if(evt.type == sf::Event::KeyPressed)
        {
            if(evt.key.code == sf::Keyboard::Enter)
            {
                textOutput->addLine(inputField->getTextAndClear());
            }

        }
        else if (evt.type == sf::Event::MouseButtonPressed)
        {
            if (evt.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mousePos = window_->mapPixelToCoords(sf::Mouse::getPosition(*window_));
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
        }*/
    }

    //Update Components


    //Clear Window
    window_->clear();

    //Draw Components

    for (auto comp : drawable_objects_) {
        comp->Draw(window_);
    }


    //display
    window_->display();


    //end
    return true;


}

void sd::Application::clear() {
    //textOutput->toggleGlitch();
    //text->setString("");
}


