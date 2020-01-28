//
// Created by christian.heusser on 07.01.2020.
//

#include <algorithm>
#include <Event/NewWordCollectedEventArgs.h>
#include <Event/TextOutputCreatedEventArgs.h>
#include <Event/PlayerVocabChangedEventArgs.h>
#include <Event/EventSystem.h>
#include <ScriptEngine/ScriptEngine.h>
#include "PlayerVocabulary.h"
#include "Word.h"
#include "Vocabulary.h"

sd::PlayerVocabulary::PlayerVocabulary() {
    actions_ = new std::vector<std::string>();
    modifiers_ = new std::vector<std::string>();
    navigation_ = new std::vector<std::string>();
    
    add_action("Honk");
    add_action("Poke");
    
    add_modifier("Flirty");
    add_modifier("Pyro");
    
    ScriptEngine::Get()->register_all("add_action", &PlayerVocabulary::add_action, this);
    ScriptEngine::Get()->register_all("add_modifier", &PlayerVocabulary::add_modifier, this);
    ScriptEngine::Get()->register_all("add_navigation", &PlayerVocabulary::add_navigation, this);
}

sd::PlayerVocabulary::~PlayerVocabulary() {
    delete actions_;
    actions_ = nullptr;

    delete modifiers_;
    modifiers_ = nullptr;

    delete navigation_;
    navigation_ = nullptr;
}

bool sd::PlayerVocabulary::has_word(std::string word) {
    if(std::count(actions_->begin(), actions_->end(), word))
    {
        return true;
    }
    if(std::count(modifiers_->begin(), modifiers_->end(), word))
    {
        return true;
    }
    if(std::count(navigation_->begin(), navigation_->end(), word))
    {
        return true;
    }
    return false;
}

void sd::PlayerVocabulary::add_action(std::string action) {
    actions_->emplace_back(action);
}

void sd::PlayerVocabulary::add_modifier(std::string modifier) {
    modifiers_->emplace_back(modifier);
}

void sd::PlayerVocabulary::add_navigation(std::string word) {
    navigation_->emplace_back(word);
}

std::vector<std::string> *sd::PlayerVocabulary::get_actions() {
    return actions_;
}

std::vector<std::string> *sd::PlayerVocabulary::GetModifiers() {
    return modifiers_;
}

std::vector<std::string> *sd::PlayerVocabulary::GetNavigation() {
    return navigation_;
}

void sd::PlayerVocabulary::handle(std::shared_ptr<EventArgs> _e) {
    if (_e->type == sd::EventArgs::Type::NEW_WORD_COLLECTED)
    {
        auto e = dynamic_cast<NewWordCollectedEventArgs*>(_e.get());

        if(!has_word(e->word)) {
            auto word = sd::Vocabulary::all_words->get(e->word);

            switch (word->get_type()) {
                case (sd::Word::Type::ACTION):add_action(e->word);
                    break;
                case (sd::Word::Type::MODIFIER):add_modifier(e->word);
                    break;
                case (sd::Word::Type::NAVIGATION):add_navigation(e->word);
                    break;
            }


            std::shared_ptr<PlayerVocabChangedEventArgs> args;
            args = std::make_shared<PlayerVocabChangedEventArgs>(
                Sp<PlayerVocabulary>(this)
                    );
            EventSystem::get().trigger(args);
        }
    }
}
