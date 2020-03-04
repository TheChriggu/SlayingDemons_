//
// Created by christian.heusser on 05.11.2019.
//

#include "Application.h"
#include "UI/Panel.h"
#include "IO/UserInput.h"
#include "Event/EventSystem.h"
#include "RoutineManager.h"
#include <iostream>
#include <map>
#include <Combat/MonsterList.h>
#include <memory>
#include <Event/FontsCreatedEventArgs.h>
#include <Event/LineToOutputEventArgs.h>
#include <Event/ColorsCreatedEventArgs.h>

bool sd::Application::setup_splash_screens() {
    splash_screens_ = std::make_shared<SplashScreens>();
    return true;
}
bool sd::Application::run_splash_screens() {
    if (!window_->isOpen())
    {
        return false;
    }

    //Draw Components
    screen_->clear();
    if(!splash_screens_->DrawTo(screen_->get_texture()))
    {
        audio_player_ = std::make_shared<AudioPlayer>();
        return false;
    }
    screen_->display();

    window_->clear();
    screen_->draw_to(window_);
    window_->display();

    //end
    return true;
}

bool sd::Application::setup()
{
    bool result = false;
    
    new EventSystem();
    new ScriptEngine();
    new RoutineManager();
    
    std::cout << "Initialize Script Engine" << std::endl;
    
    // Add Config file to engine
    ScriptEngine::get().add_script("../Resources/config.lua");
    // Add other scripts
    // TODO(FK): find out why Game crashes when tmp test var is not used
    auto files = FileInput::get_files("../Resources/Scripts/");
    for (const auto &file : *files)
    {
        ScriptEngine::get().add_script(file);
    }
    
    result = setup_window();
    if (!result) return false;
    
    shader_engine_ = std::make_shared<ShaderEngine>(drawable_objects_);
    shader_engine_->add_drawable_object(screen_);
    shader_engine_->setup_all_shader();
    
    world_ = std::make_shared<World>();
    
    // TODO(FK)
    new UserInput(window_.get());
    
    result = setup_scene();
    if (!result) return false;
    
    load_vocab();
    new sd::MonsterList();
    
    fonts_ = std::make_shared<Font>();
    EventSystem::get().trigger(std::make_shared<FontsCreatedEventArgs>(fonts_));

    colors_ = std::make_shared<Colors>();
    EventSystem::get().trigger(std::make_shared<ColorsCreatedEventArgs>(colors_));

    world_->setup();
    for (const auto &object : drawable_objects_)
    {
        object->setup();
    }

    ScriptEngine::get().set_broadcast_locked(false);


    std::cout << "End initialization\n";
    
    RoutineManager::get().start_routine(
        std::make_shared<Routine>(
            nullptr,
            3,
            CREATE_ROUTINE_BODY(
                test();
                return Routine::end;
                )
            )
        );
    
    return true;
}



bool sd::Application::run()
{
    
    if (!window_->isOpen())
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

        if(evt.type == sf::Event::GainedFocus)
        {
            auto args = std::make_shared<EventArgs>(EventArgs());
            args->type = sd::EventArgs::Type::GAINED_FOCUS;
            EventSystem::get().trigger(args);
        }
        
        for (const auto &object : drawable_objects_)
        {
            object->handle(evt);
        }
    }
    
    //Update Routines
    RoutineManager::get().process();
    
    
    //Draw Components
    //window_->clear();
    screen_->clear();
    for (const auto &comp : drawable_objects_)
    {
        comp->draw_to(screen_->get_texture());
    }
    screen_->display();

    window_->clear();
    screen_->draw_to(window_);
    window_->display();
    
    
    //end
    return true;
    
}

void sd::Application::load_vocab()
{
    auto vocab = std::make_shared<Vocabulary>();
    
    auto table = FileInput::load_tsv("../Resources/Tables/Actions.tsv");
    for (auto line : *table)
    {
        if (line[0] != "Name")
        {
            auto action = std::make_shared<Action>(line);
            std::string name{line[0]};
            strtk::convert_to_lowercase(name);

            vocab->add(name, action);
        }
    }
    
    table = FileInput::load_tsv("../Resources/Tables/Modifiers.tsv");
    for (auto line : *table)
    {
        if (line[0] != "Name")
        {
            auto modifier = std::make_shared<Modifier>(line);
            std::string name{line[0]};
            strtk::convert_to_lowercase(name);
            
            vocab->add(name, modifier);
        }
    }
    
    /*auto walk_to = std::make_shared<Word>();
    auto jump_over = std::make_shared<Word>();
    vocab->add("walk to", walk_to);
    vocab->add("jump over", jump_over);*/
    
    Vocabulary::all_words = vocab;
}

void sd::Application::shutdown()
{

}

bool sd::Application::setup_window()
{
    auto config = ScriptEngine::get().get_script("config");
    if (!config) return false;
    
    auto window_info = config->get_table("window");
    if (!window_info) return false;
    
    window_ = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(
            window_info.value()["size"]["x"].get_or(1920),
            window_info.value()["size"]["y"].get_or(1080)),
        window_info.value()["title"].get_or<std::string>("Slaying_Demons_"),
        sf::Style::Default);
    
    window_->setFramerateLimit(60);

    screen_ = std::make_shared<Screen>(window_->getSize());
    return true;
}

bool sd::Application::setup_scene()
{
    std::cout << "Start initialization.\n";
    
    std::cout << "Create background panel\n";
    auto panel = new Panel(sf::Vector2f(0.0, 0.0), sf::Vector2f(1920, 1080), "../Resources/Sprites/Progressing/background_");
    panel->set_name("background_panel");
    drawable_objects_.emplace_back(Sp<Panel>(panel));
    // TODO(FK): clean up this shit
    
    std::cout << "Create text output background\n";
    auto outputBackground = new Panel(sf::Vector2f(41.8, 75.8), sf::Vector2f(1044, 1008), "../Resources/Sprites/Progressing/output_");
    outputBackground->set_name("output-panel");
    drawable_objects_.emplace_back(Sp<Panel>(outputBackground));
    
    std::cout << "Create words panel\n";
    drawable_objects_.emplace_back(std::make_shared<PossibleWords>(
        sf::Vector2f(19.1, 597.9),
        sf::Vector2f(1059, 445)));
    
    std::cout << "emplace Inputfield\n";
    std::cout << "Create input field\n";
    InputField *inputField = new InputField(sf::Vector2f(80, 940), sf::Vector2f(1025, 63), sf::Color::Magenta);
    drawable_objects_.emplace_back(Sp<InputField>(inputField));
    
    
    
    std::cout << "Create text output\n";
    drawable_objects_.emplace_back(std::make_shared<TextOutput>(sf::Vector2f(90.0, 100.0), sf::Vector2f(1044, 1008), sf::Color::Red));
    
    std::cout << "Create Map panel\n";
    MapWindow *mapWindow = new MapWindow(sf::Vector2f(1122.8, 79.9), sf::Vector2f(761, 558));
    drawable_objects_.emplace_back(Sp<MapWindow>(mapWindow));
    
    
    
    //std::cout << "Create button\n";
    //drawable_objects_.emplace_back(new Button(sf::Vector2f(1200.0f,500.0f), sf::Vector2f(1.0f,1.0f), [&]{clear();}));
    
    //possibleWords->SetPlayerVocab(inputTextProcessor->GetPlayerState()->GetPlayerVocabulary());
    //possibleWords->Update();
    return true;
}

void sd::Application::test()
{
    auto event = std::make_shared<LineToOutputEventArgs>("test");
    EventSystem::get().trigger(event);
}


