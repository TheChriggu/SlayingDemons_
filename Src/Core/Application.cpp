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


bool sd::Application::setup()
{
    bool result = false;
    
    new EventSystem();
    new ScriptEngine();
    
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
    shader_engine_->setup_all_shader();
    
    
    // TODO(FK)
    new UserInput(window_.get());
    
    result = setup_scene();
    if (!result) return false;
    
    load_vocab();
    new sd::MonsterList();
    new sd::Font();

    for (const auto &object : drawable_objects_)
    {
        object->setup();
    }


    
    std::cout << "End initialization\n";
    
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
        
        for (const auto &object : drawable_objects_)
        {
            object->handle(evt);
        }
    }
    
    //Update Components
    
    //Clear Window
    window_->clear();
    
    //Draw Components
    
    for (const auto &comp : drawable_objects_)
    {
        comp->draw_to(window_);
    }
    
    //display
    window_->display();
    
    
    //end
    return true;
    
}

void sd::Application::load_vocab()
{
    
    auto vocab = std::make_shared<Vocabulary>();
    
    auto table = FileInput::load_csv("../Resources/Tables/Actions.csv");
    for (auto line : *table)
    {
        if (line[0] != "Name")
        {
            auto action = std::make_shared<Action>();
            action->set_name(line[0]);
            action->set_stats({stof(line[1]), stof(line[2]), stof(line[3]), stof(line[4]), stof(line[5]),
                                  stof(line[6]), stof(line[7]), stof(line[8])});
    
            vocab->add(line[0], action);
        }
    }
    
    table = FileInput::load_csv("../Resources/Tables/Modifiers.csv");
    for (auto line : *table)
    {
        if (line[0] != "Name")
        {
            auto modifier = std::make_shared<Modifier>();
            modifier->set_name(line[0]);
            Stats stats = {stof(line[2]), stof(line[4]), stof(line[6]), stof(line[8]), stof(line[10]),
                stof(line[12]), stof(line[14]), stof(line[16])};
            StatwiseOperation stat_ops;
            stat_ops.speed = stat_ops.from_string(line[1]);
            stat_ops.accuracy = stat_ops.from_string(line[3]);
            stat_ops.physical = stat_ops.from_string(line[5]);
            stat_ops.mental = stat_ops.from_string(line[7]);
            stat_ops.fire = stat_ops.from_string(line[9]);
            stat_ops.water = stat_ops.from_string(line[11]);
            stat_ops.tree = stat_ops.from_string(line[13]);
            stat_ops.earth = stat_ops.from_string(line[15]);
    
            modifier->set_stats(stats, stat_ops);
            vocab->add(line[0], modifier);
        }
    }
    
    auto walk_to = std::make_shared<Word>();
    auto jump_over = std::make_shared<Word>();
    vocab->add("walk to", walk_to);
    vocab->add("jump over", jump_over);
    
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
    
    return true;
}

bool sd::Application::setup_scene()
{
    std::cout << "Start initialization.\n";
    
    std::cout << "Create background panel\n";
    auto panel = new Panel(sf::Vector2f(0.0, 0.0), sf::Vector2f(1920, 1080), "../Resources/Sprites/fantasy_background.png");
    panel->set_name("background_panel");
    drawable_objects_.emplace_back(Sp<Panel>(panel));
    // TODO(FK): clean up this shit
    
    std::cout << "Create text output background\n";
    auto outputBackground = new Panel(sf::Vector2f(48.0, 41.0), sf::Vector2f(1044, 1008), "../Resources/Sprites/fantasy_textoutput.png");
    outputBackground->set_name("output-panel");
    drawable_objects_.emplace_back(Sp<Panel>(outputBackground));
    
    std::cout << "Create words panel\n";
    drawable_objects_.emplace_back(std::make_shared<PossibleWords>(
        sf::Vector2f(39.0, 575.0),
        sf::Vector2f(1059, 445),
        "../Resources/Sprites/fantasy_input.png"));
    
    std::cout << "emplace Inputfield\n";
    std::cout << "Create input field\n";
    InputField *inputField = new InputField(sf::Vector2f(80, 940), sf::Vector2f(1025, 63), sf::Color::Magenta);
    drawable_objects_.emplace_back(Sp<InputField>(inputField));
    
    
    
    std::cout << "Create text output\n";
    drawable_objects_.emplace_back(std::make_shared<TextOutput>(sf::Vector2f(90.0, 100.0), sf::Vector2f(1044, 1008), sf::Color::Red));
    
    std::cout << "Create Map panel\n";
    MapWindow *mapWindow = new MapWindow(sf::Vector2f(1127.0, 41.0), sf::Vector2f(761, 558));
    drawable_objects_.emplace_back(Sp<MapWindow>(mapWindow));
    
    
    
    //std::cout << "Create button\n";
    //drawable_objects_.emplace_back(new Button(sf::Vector2f(1200.0f,500.0f), sf::Vector2f(1.0f,1.0f), [&]{clear();}));
    
    //possibleWords->SetPlayerVocab(inputTextProcessor->GetPlayerState()->GetPlayerVocabulary());
    //possibleWords->Update();
    return true;
}


