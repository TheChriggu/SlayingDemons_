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
    // TODO: Remove hardcoded add-statements
    add_action("Honk");
    add_action("Poke");
    
    add_modifier("Flirty");
    add_modifier("Pyro");
    
    ScriptEngine::get().register_all("add_action", &PlayerVocabulary::add_action, this);
    ScriptEngine::get().register_all("add_modifier", &PlayerVocabulary::add_modifier, this);
    ScriptEngine::get().register_all("add_navigation", &PlayerVocabulary::add_navigation, this);
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
    if(std::count(navigation_.begin(), navigation_.end(), word))
    {
        return true;
    }
    return false;
}

void sd::PlayerVocabulary::add_action(const std::string& action) {
    actions_.emplace_back(action);
}

void sd::PlayerVocabulary::add_modifier(const std::string& modifier) {
    modifiers_.emplace_back(modifier);
}

void sd::PlayerVocabulary::add_navigation(const std::string& word) {
    navigation_.emplace_back(word);
}

std::vector<std::string>& sd::PlayerVocabulary::get_actions() {
    return actions_;
}

std::vector<std::string>& sd::PlayerVocabulary::get_modifiers() {
    return modifiers_;
}

std::vector<std::string>& sd::PlayerVocabulary::get_navigation() {
    return navigation_;
}

void sd::PlayerVocabulary::handle(std::shared_ptr<EventArgs> e) {
    if (e->type == sd::EventArgs::Type::NEW_WORD_COLLECTED)
    {
        auto args = std::dynamic_pointer_cast<NewWordCollectedEventArgs>(e);

        if(!has_word(args->word)) {
            auto word = sd::Vocabulary::all_words->get(args->word);

            switch (word->get_type()) {
                case (sd::Word::Type::ACTION):add_action(args->word);
                    break;
                case (sd::Word::Type::MODIFIER):add_modifier(args->word);
                    break;
                case (sd::Word::Type::NAVIGATION):add_navigation(args->word);
                    break;
            }


            std::shared_ptr<PlayerVocabChangedEventArgs> event = std::make_shared<PlayerVocabChangedEventArgs>();
            EventSystem::get().trigger(event);
        }
    }
}
