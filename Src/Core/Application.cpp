//
// Created by christian.heusser on 05.11.2019.
//

#include "Application.h"
#include "UI/Panel.h"
#include "IO/UserInput.h"
#include "Event/EventSystem.h"
#include <iostream>
#include <map>
#include <Combat/MonsterList.h>
#include <memory>


sd::Vocabulary* sd::Vocabulary::allWords = nullptr;

sd::Application::Application()
{
}



bool sd::Application::Setup() {
    window_ = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "MyGame", sf::Style::Default);
    window_->setFramerateLimit(60);

    new EventSystem();

    std::cout << "Initialize Script Engine" << std::endl;
    new ScriptEngine();
    auto script_engine_ = ScriptEngine::Get();

    std::cout << "get test file\n";
    // TODO(FK): find out why Game crashes when tmp test var is not used
    auto test = FileInput::GetFiles("../Resources/Scripts/");
    std::cout << "add files\n";
    for (auto file : *test) {
        script_engine_->AddScript(file);
    }


    shader_engine_ = std::make_shared<ShaderEngine>(drawable_objects_);
    shader_engine_->SetupAllShader();


    // TODO(FK)
    new UserInput(window_.get());

    std::cout << "Start initialization.\n";

    std::cout << "Create background panel\n";
    auto panel = new Panel(sf::Vector2f(0.0, 0.0), sf::Vector2f(1920, 1080), "../Resources/Sprites/fantasy_background.png");
    panel->SetName("background_panel");
    drawable_objects_.emplace_back(sp<Panel>(panel));
    // TODO(FK): clean up this shit

    std::cout << "Create text output background\n";
    auto outputBackground = new Panel(sf::Vector2f(48.0,41.0), sf::Vector2f(1044,1008), "../Resources/Sprites/fantasy_textoutput.png");
    outputBackground->SetName("output-panel");
    drawable_objects_.emplace_back(sp<Panel>(outputBackground));

    std::cout << "emplace Inputfield\n";
    std::cout << "Create input field\n";
    InputField* inputField = new InputField(sf::Vector2f(80,940), sf::Vector2f(1025,63), sf::Color::Magenta);
    drawable_objects_.emplace_back(sp<InputField>(inputField));


    std::cout << "Create words panel\n";
    drawable_objects_.emplace_back(std::make_shared<PossibleWords>(
            sf::Vector2f(39.0, 605.0),
            sf::Vector2f(1059, 445),
            "../Resources/Sprites/fantasy_input.png"));

    std::cout << "Create text output\n";
    drawable_objects_.emplace_back(std::make_shared<TextOutput>(sf::Vector2f(90.0,100.0), sf::Vector2f(1044,1008), sf::Color::Red));

    std::cout << "Create Map panel\n";
    MapWindow* mapWindow = new MapWindow(sf::Vector2f(1127.0, 41.0), sf::Vector2f(761, 558));
    drawable_objects_.emplace_back(sp<MapWindow>(mapWindow));



    //std::cout << "Create button\n";
    //drawable_objects_.emplace_back(new Button(sf::Vector2f(1200.0f,500.0f), sf::Vector2f(1.0f,1.0f), [&]{clear();}));

    //possibleWords->SetPlayerVocab(inputTextProcessor->GetPlayerState()->GetPlayerVocabulary());
    //possibleWords->Update();



    std::cout << "Create global vocabulary containing all words\n";
    LoadVocab();
    new sd::MonsterList();

    for(const auto& object : drawable_objects_) {
        object->Setup();
    }

    //auto test24 = typeof(this);
    //std::cout << " " <<  << std::endl;

    //shader_engine_->SetGlitchOn("output-panel");
    //shader_engine_->SetWeakglitchOn("background_panel");

    //script_engine_->Broadcast("update");

    std::cout << "End initialization\n";

    return true;
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

        for (const auto& object : drawable_objects_) {
            object->Handle(evt);
        }
    }

    //Update Components

    //Clear Window
    window_->clear();

    //Draw Components

    for (const auto& comp : drawable_objects_) {
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

    auto table = FileInput::LoadCSV("../Resources/Tables/Actions.csv");
    for(auto line : *table)
    {
        if(line[0] != "Name")
        {
            Action* action = new Action();
            action->SetName(line[0]);
            action->SetStats({stof(line[1]),stof(line[2]),stof(line[3])
                              ,stof(line[4]),stof(line[5]),stof(line[6])
                              ,stof(line[7]),stof(line[8])});

            vocab->Add(line[0], action);
        }
    }



    table = FileInput::LoadCSV("../Resources/Tables/Modifiers.csv");
    for(auto line : *table)
    {
        if(line[0] != "Name")
        {
            Modifier* modifier = new Modifier();
            modifier->SetName(line[0]);
            Stats stats = {stof(line[2]),stof(line[4]),stof(line[6])
                    ,stof(line[8]),stof(line[10]),stof(line[12])
                    ,stof(line[14]),stof(line[16])};
            StatwiseOperation statOps;
            statOps.speed = statOps.FromString(line[1]);
            statOps.accuracy = statOps.FromString(line[3]);
            statOps.physical = statOps.FromString(line[5]);
            statOps.mental = statOps.FromString(line[7]);
            statOps.fire = statOps.FromString(line[9]);
            statOps.water = statOps.FromString(line[11]);
            statOps.tree = statOps.FromString(line[13]);
            statOps.earth = statOps.FromString(line[15]);

            modifier->SetStats(stats,statOps);
            vocab->Add(line[0], modifier);
        }
    }


    Word* walkTo = new Word();
    Word* jumpOver = new Word();
    vocab->Add("walk to", walkTo);
    vocab->Add("jump over", jumpOver);

    Vocabulary::allWords = vocab;
}

void sd::Application::Shutdown() {

}


