//
// Created by christian.heusser on 05.11.2019.
//

#include "Application.h"
#include "Panel.h"
#include "UserInput.h"
#include <iostream>

sd::Application::Application()
{
    window_ = nullptr;
    world_ = nullptr;
    file_input_ = nullptr;
}



bool sd::Application::Setup() {
    window_ = new sf::RenderWindow(sf::VideoMode(1920, 1080), "MyGame");
    window_->setFramerateLimit(60);

    // TODO(FK)
    new UserInput(window_);

    std::cout << "Start initialization.\n";


    std::cout << "Create first panel\n";
    drawable_objects_.emplace_back(new Panel(sf::Vector2f(0.0, 0.0), sf::Vector2f(1920, 1080), sf::Color::Blue));
    // TODO(FK): clean up this shit
    std::cout << "Create text output\n";
    auto output = new TextOutput(sf::Vector2f(48.0,41.0), sf::Vector2f(1044,1008), sf::Color::Red);
    drawable_objects_.emplace_back(output);
    std::cout << "Create second panel\n";
    drawable_objects_.emplace_back(new Panel(sf::Vector2f(39.0, 605.0), sf::Vector2f(1059, 445), sf::Color::Green));
    std::cout << "Create third panel\n";
    drawable_objects_.emplace_back(new InputField(sf::Vector2f(55,977), sf::Vector2f(1025,63), sf::Color::Magenta, output));
    std::cout << "Create fourth panel\n";
    drawable_objects_.emplace_back(new Panel(sf::Vector2f(1127.0, 41.0), sf::Vector2f(761, 558), sf::Color::Magenta));
    std::cout << "Create fifth panel\n";
    drawable_objects_.emplace_back(new Panel(sf::Vector2f(1103.0, 611.0), sf::Vector2f(816, 461), sf::Color::Red));
    std::cout << "Create button\n";
    drawable_objects_.emplace_back(new Button(sf::Vector2f(1200.0f,500.0f), sf::Vector2f(1.0f,1.0f), [&]{clear();}));

    std::cout << "Create global vocabulary containing all words\n";
    Vocabulary::allWords = new Vocabulary();
    //add words to vocabulary

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

        for (auto object : drawable_objects_) {
            object->Handle(evt);
        }
    }

    //Update Components


    //Clear Window
    window_->clear();

    //Draw Components

    for (auto comp : drawable_objects_) {
        comp->DrawTo(window_);
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


