//
// Created by christian.heusser on 05.11.2019.
//

#include "Application.h"
#include "Panel.h"
#include "UserInput.h"
#include <iostream>


sd::Vocabulary* sd::Vocabulary::allWords = nullptr;

sd::Application::Application()
{
    window_ = nullptr;
    world_ = nullptr;
    file_input_ = nullptr;
}



bool sd::Application::Setup() {
    window_ = new sf::RenderWindow(sf::VideoMode(1920, 1080), "MyGame", sf::Style::Fullscreen);
    window_->setFramerateLimit(60);

    // TODO(FK)
    new UserInput(window_);

    std::cout << "Start initialization.\n";

    std::cout << "Create background panel\n";
    sf::Texture* backgroundTexture = new sf::Texture();
    backgroundTexture->loadFromFile("../Resources/Sprites/fantasy_background.png");
    drawable_objects_.emplace_back(new Panel(sf::Vector2f(0.0, 0.0), sf::Vector2f(1920, 1080), backgroundTexture));
    // TODO(FK): clean up this shit

    std::cout << "Create text output background\n";
    sf::Texture* textOutputBackground = new sf::Texture();
    textOutputBackground->loadFromFile("../Resources/Sprites/fantasy_textoutput.png");
    auto outputBackground = new Panel(sf::Vector2f(48.0,41.0), sf::Vector2f(1044,1008), textOutputBackground);
    drawable_objects_.emplace_back(outputBackground);



    std::cout << "Create words panel\n";
    sf::Texture* wordsTexture = new sf::Texture();
    wordsTexture->loadFromFile("../Resources/Sprites/fantasy_input.png");
    drawable_objects_.emplace_back(new Panel(sf::Vector2f(39.0, 605.0), sf::Vector2f(1059, 445), wordsTexture));

    std::cout << "Create text output\n";
    output = new TextOutput(sf::Vector2f(90.0,100.0), sf::Vector2f(1044,1008), sf::Color::Red);
    drawable_objects_.emplace_back(output);

    std::cout << "Create Map panel\n";
    sf::Texture* mapTexture = new sf::Texture();
    mapTexture->loadFromFile("../Resources/Sprites/fantasy_map.png");
    drawable_objects_.emplace_back(new Panel(sf::Vector2f(1127.0, 41.0), sf::Vector2f(761, 558), mapTexture));




    //create input field
    drawable_objects_.emplace_back(new InputField(sf::Vector2f(80,940), sf::Vector2f(1025,63), sf::Color::Magenta, output));




    //std::cout << "Create fourth panel\n";
    //drawable_objects_.emplace_back(new Panel(sf::Vector2f(1127.0, 41.0), sf::Vector2f(761, 558), sf::Color::Magenta));
    //std::cout << "Create fifth panel\n";
    //drawable_objects_.emplace_back(new Panel(sf::Vector2f(1103.0, 611.0), sf::Vector2f(816, 461), sf::Color::Red));
    //std::cout << "Create button\n";
    //drawable_objects_.emplace_back(new Button(sf::Vector2f(1200.0f,500.0f), sf::Vector2f(1.0f,1.0f), [&]{clear();}));

    std::cout << "Create global vocabulary containing all words\n";
    LoadVocab();

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

void sd::Application::LoadVocab() {

    Vocabulary* vocab = new Vocabulary();


    Action* honk = new Action();
    honk->SetName("honk");
    honk->SetStats({10,10,2,20,1,1,1,1,1});
    Action* smash = new Action();
    smash->SetName("smash");
    smash->SetStats({5,10,15,2,2,5,5,10,7});
    Action* scratch = new Action();
    scratch->SetName("scratch");
    scratch->SetStats({15,5,10,7,1,1,10,10,7});
    Action* howl = new Action();
    howl->SetName("howl");
    howl->SetStats({5,20,3,15,1,1,1,1,2});
    Modifier* flirty = new Modifier();
    flirty->SetName("flirty");
    flirty->SetStats({3,0.5, 0.3, -2,0.5,0.5,0.5,0.5,0.5},
            {sd::StatwiseOperation::Add,
             sd::StatwiseOperation::Mult,
             sd::StatwiseOperation::Mult,
             sd::StatwiseOperation::Mult,
             sd::StatwiseOperation::Mult,
             sd::StatwiseOperation::Mult,
             sd::StatwiseOperation::Mult,
             sd::StatwiseOperation::Mult,
             sd::StatwiseOperation::Mult});
    Modifier* heavy = new Modifier();
    heavy->SetName("heavy");
    heavy->SetStats({0.4,2, 3, 1,5,5,5,5,5},
                     {sd::StatwiseOperation::Mult,
                      sd::StatwiseOperation::Mult,
                      sd::StatwiseOperation::Mult,
                      sd::StatwiseOperation::Mult,
                      sd::StatwiseOperation::Add,
                      sd::StatwiseOperation::Add,
                      sd::StatwiseOperation::Add,
                      sd::StatwiseOperation::Add,
                      sd::StatwiseOperation::Add});
    Modifier* monstrous = new Modifier();
    monstrous->SetName("monstrous");
    monstrous->SetStats({0.2, 1.5, 2,2,2,2,2,2},
                    {sd::StatwiseOperation::Mult,
                     sd::StatwiseOperation::Mult,
                     sd::StatwiseOperation::Add,
                     sd::StatwiseOperation::Mult,
                     sd::StatwiseOperation::Add,
                     sd::StatwiseOperation::Add,
                     sd::StatwiseOperation::Add,
                     sd::StatwiseOperation::Add,
                     sd::StatwiseOperation::Add});
    Modifier* loud = new Modifier();
    loud->SetName("loud");
    loud->SetStats({10, 10, 0.1,2,5,5,5,5},
                        {sd::StatwiseOperation::Add,
                         sd::StatwiseOperation::Add,
                         sd::StatwiseOperation::Mult,
                         sd::StatwiseOperation::Mult,
                         sd::StatwiseOperation::Add,
                         sd::StatwiseOperation::Add,
                         sd::StatwiseOperation::Add,
                         sd::StatwiseOperation::Add,
                         sd::StatwiseOperation::Add});
    Word* walkTo = new Word();
    Word* jumpOver = new Word();

    vocab->Add("honk", honk);
    vocab->Add("smash", smash);
    vocab->Add("scratch", scratch);
    vocab->Add("howl", howl);
    vocab->Add("flirty",flirty);
    vocab->Add("heavy", heavy);
    vocab->Add("monstrous", monstrous);
    vocab->Add("loud", loud);
    vocab->Add("walk to", walkTo);
    vocab->Add("jump over", jumpOver);

    Vocabulary::allWords = vocab;
    //add words to vocabulary
}


