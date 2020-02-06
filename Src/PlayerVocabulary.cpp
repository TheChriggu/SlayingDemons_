//
// Created by christian.heusser on 07.01.2020.
//

#include <algorithm>
#include <Event/NewWordCollectedEventArgs.h>
#include <Event/TextOutputCreatedEventArgs.h>
#include <Event/PlayerVocabChangedEventArgs.h>
#include <Event/EventSystem.h>
#include <ScriptEngine/ScriptEngine.h>
#include <IO/FileInput.h>
#include "PlayerVocabulary.h"
#include "Word.h"
#include "Vocabulary.h"

sd::PlayerVocabulary::PlayerVocabulary() {
    actions_trie_ = std::make_shared<Trie>();
    modifiers_trie_ = std::make_shared<Trie>();
    commands_trie_ = std::make_shared<Trie>();

    auto table = FileInput::load_tsv("../Resources/Tables/PlayerVocab.tsv");
    for(const auto& word : (*table)[0])
    {
        add_action(word);
    }
    for(const auto& word : (*table)[1])
    {
        add_modifier(word);
    }
    for(const auto& word : (*table)[2])
    {
        add_command(word);
    }
    
    ScriptEngine::get().register_all("add_action", &PlayerVocabulary::add_action, this);
    ScriptEngine::get().register_all("add_modifier", &PlayerVocabulary::add_modifier, this);
    ScriptEngine::get().register_all("add_command", &PlayerVocabulary::add_command, this);
}

bool sd::PlayerVocabulary::has_word(const std::string& word) {
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

void sd::PlayerVocabulary::add_action(const std::string& action) {
    actions_.emplace_back(action);
    actions_trie_->add_word(action);
}

void sd::PlayerVocabulary::add_modifier(const std::string& modifier) {
    modifiers_.emplace_back(modifier);
    modifiers_trie_->add_word(modifier);
}

void sd::PlayerVocabulary::add_command(const std::string& word) {
    commands_.emplace_back(word);
    commands_trie_->add_word(word);
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

void sd::PlayerVocabulary::handle(std::shared_ptr<EventArgs> e) {
    if (e->type == sd::EventArgs::Type::NEW_WORD_COLLECTED)
    {
        auto args = std::dynamic_pointer_cast<NewWordCollectedEventArgs>(e);

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
}

