//
// Created by christian.heusser on 07.01.2020.
//

#include <algorithm>
#include <utility>
#include <Event/NewWordCollectedEventArgs.h>
#include <Event/TextOutputCreatedEventArgs.h>
#include <Event/PlayerVocabChangedEventArgs.h>
#include <Event/EventSystem.h>
#include <ScriptEngine/ScriptEngine.h>
#include <IO/FileInput.h>
#include "PlayerVocabulary.h"
#include "Word.h"
#include "Vocabulary.h"

sd::PlayerVocabulary::PlayerVocabulary() : Subscriber() {
    
    CREATE_EVENT_HANDLER(
        if (e->type == sd::EventArgs::Type::NEW_WORD_COLLECTED)
        {
            auto args = std::dynamic_pointer_cast<NewWordCollectedEventArgs>(e);
            std::cout << "-- added new word: " << args->word << std::endl;
            
            if(!has_word(args->word)) {
                auto word = sd::Vocabulary::all_words->get(args->word);
            
                std::shared_ptr<PlayerVocabChangedEventArgs> event = std::make_shared<PlayerVocabChangedEventArgs>();
            
                switch (word->get_type()) {
                    case (sd::Word::Type::ACTION):
                        add_action(args->word);
                        event->change_type = sd::Word::Type::ACTION;
                        break;
                    case (sd::Word::Type::MODIFIER):
                        add_modifier(args->word);
                        event->change_type = sd::Word::Type::MODIFIER;
                        break;
                    case (sd::Word::Type::COMMAND):
                        add_command(args->word);
                        event->change_type = sd::Word::Type::COMMAND;
                        break;
                }
            
                EventSystem::get().trigger(event);
            }
        }
        );
    
    REGISTER_EVENT_HANDLER();
    
    actions_trie_ = std::make_shared<Trie>();
    modifiers_trie_ = std::make_shared<Trie>();
    commands_trie_ = std::make_shared<Trie>();

    load();
    
    ScriptEngine::get().register_all("add_action", &PlayerVocabulary::add_action, this);
    ScriptEngine::get().register_all("add_modifier", &PlayerVocabulary::add_modifier, this);
    ScriptEngine::get().register_all("add_command", &PlayerVocabulary::add_command, this);
}

bool sd::PlayerVocabulary::has_word(const std::string& word) {
    for (const auto& action : modifiers_) {
        std::cout << action << " : " << word << std::endl;
    }
    if(std::count(actions_.begin(), actions_.end(), word))
    {
        return true;
    }
    if(std::count(modifiers_.begin(), modifiers_.end(), word))
    {
        return true;
    }
    if(std::count(commands_.begin(), commands_.end(), word))
    {
        return true;
    }
    return false;
}

void sd::PlayerVocabulary::add_action(std::string action) {
    strtk::convert_to_lowercase(action);
    if(has_word(action))
    {
        return;
    }
    actions_.emplace_back(action);
    actions_trie_->add_word(action);
}

void sd::PlayerVocabulary::add_modifier(std::string modifier) {
    strtk::convert_to_lowercase(modifier);
    if(has_word(modifier))
    {
        return;
    }
    modifiers_.emplace_back(modifier);
    modifiers_trie_->add_word(modifier);
}

void sd::PlayerVocabulary::add_command(std::string word) {
    strtk::convert_to_lowercase(word);
    if(has_word(word))
    {
        return;
    }
    commands_.emplace_back(word);
    commands_trie_->add_word(word);
}

void sd::PlayerVocabulary::set_objects(std::vector<std::string> objects)
{
    objects_ = std::move(objects);
    
    objects_trie_.reset();
    objects_trie_ = std::make_shared<Trie>();
    
    for (const auto& object : objects_) {
        objects_trie_->add_word(object);
    }
}

std::vector<std::string>& sd::PlayerVocabulary::get_actions() {
    return actions_;
}

std::vector<std::string>& sd::PlayerVocabulary::get_modifiers() {
    return modifiers_;
}

std::vector<std::string>& sd::PlayerVocabulary::get_commands() {
    return commands_;
}

Sp<std::vector<std::string>> sd::PlayerVocabulary::get_actions_starting_with(const std::string &prefix)
{
    return actions_trie_->get_all_that_starts_with(prefix);
}

Sp<std::vector<std::string>> sd::PlayerVocabulary::get_modifiers_starting_with(const std::string &prefix)
{
    return modifiers_trie_->get_all_that_starts_with(prefix);
}

Sp<std::vector<std::string>> sd::PlayerVocabulary::get_commands_starting_with(const std::string &prefix)
{
    return commands_trie_->get_all_that_starts_with(prefix);
}

Sp<std::vector<std::string>> sd::PlayerVocabulary::get_objects_starting_with(const std::string &prefix)
{
    return objects_trie_->get_all_that_starts_with(prefix);
}

void sd::PlayerVocabulary::save_to_file()
{
    auto vec = std::make_shared<std::vector<std::vector<std::string>>>();
    vec->emplace_back(get_modifiers());
    vec->emplace_back(get_actions());
    vec->emplace_back(get_commands());

    FileInput::write_tsv(vec, "../Resources/Tables/PlayerVocab.tsv");
}

void sd::PlayerVocabulary::load_from_file()
{
    load();

    std::shared_ptr<EventArgs> event = std::make_shared<EventArgs>();
    event->type = EventArgs::Type::PLAYER_VOCAB_CHANGED;
    EventSystem::get().trigger(event);
}

std::vector<std::string> &sd::PlayerVocabulary::get_objects()
{
    return objects_;
}

void sd::PlayerVocabulary::load() {
    actions_trie_.reset();
    actions_trie_ = std::make_shared<Trie>();
    modifiers_trie_.reset();
    modifiers_trie_ = std::make_shared<Trie>();
    commands_trie_.reset();
    commands_trie_ = std::make_shared<Trie>();
    actions_.clear();
    modifiers_.clear();
    commands_.clear();


    auto vec = FileInput::load_tsv("../Resources/Tables/PlayerVocab.tsv");

    bool start_self_destruct = false;
    for(auto row : *vec)
    {
        for (auto word : row)
        {
            std::string lcase;
            strtk::parse(word, "", strtk::as_lcase(lcase).ref());
            if(lcase.find("self") != std::string::npos || lcase.find("destruct") != std::string::npos)
            {
                actions_trie_.reset();
                actions_trie_ = std::make_shared<Trie>();
                modifiers_trie_.reset();
                modifiers_trie_ = std::make_shared<Trie>();
                commands_trie_.reset();
                commands_trie_ = std::make_shared<Trie>();

                add_modifier("self");
                add_action("destruct");;
                add_command("self_destruct");
                
                start_self_destruct = true;

                ScriptEngine::get().broadcast("self_destruct_added");
            }
        }
    }
    std::cout << "-- number commands: " << commands_.size() << std::endl;
    if(!start_self_destruct)
    {
        for(auto modifier :  (*vec)[0])
        {
            std::string lcase;
            strtk::parse(modifier, "", strtk::as_lcase(lcase).ref());
            std::string copy = lcase;
            add_modifier(copy);
        }
        for(auto action :  (*vec)[1])
        {
            std::string lcase;
            strtk::parse(action, "", strtk::as_lcase(lcase).ref());
            std::string copy = lcase;
            add_action(copy);
        }
        for(auto command :  (*vec)[2])
        {
            std::string lcase;
            strtk::parse(command, "", strtk::as_lcase(lcase).ref());
            std::string copy = lcase;
            std::cout << "-- new commands: " << copy << std::endl;
            add_command(copy);
        }
    }
    std::cout << "-- number commands: " << commands_.size() << std::endl;
}



