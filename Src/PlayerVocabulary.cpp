//
// Created by christian.heusser on 07.01.2020.
//

#include <algorithm>
#include <Event/NewWordCollectedEventArgs.h>
#include <Event/TextOutputCreatedEventArgs.h>
#include <Event/PlayerVocabChangedEventArgs.h>
#include <Event/EventSystem.h>
#include "PlayerVocabulary.h"
#include "Word.h"
#include "Vocabulary.h"

sd::PlayerVocabulary::PlayerVocabulary() {
    actions = new std::vector<std::string>();
    modifiers = new std::vector<std::string>();
    navigation = new std::vector<std::string>();

    AddAction("Honk");
    AddAction("Poke");

    AddModifier("Flirty");
    AddModifier("Pyro");
}

sd::PlayerVocabulary::~PlayerVocabulary() {
    delete actions;
    actions = nullptr;

    delete modifiers;
    modifiers = nullptr;

    delete navigation;
    navigation = nullptr;
}

bool sd::PlayerVocabulary::HasWord(std::string word) {
    if(std::count(actions->begin(),actions->end(),word))
    {
        return true;
    }
    if(std::count(modifiers->begin(),modifiers->end(),word))
    {
        return true;
    }
    if(std::count(navigation->begin(),navigation->end(),word))
    {
        return true;
    }
    return false;
}

void sd::PlayerVocabulary::AddAction(std::string action) {
    actions->emplace_back(action);
}

void sd::PlayerVocabulary::AddModifier(std::string modifier) {
    modifiers->emplace_back(modifier);
}

void sd::PlayerVocabulary::AddNavigation(std::string word) {
    navigation->emplace_back(word);
}

std::vector<std::string> *sd::PlayerVocabulary::GetActions() {
    return actions;
}

std::vector<std::string> *sd::PlayerVocabulary::GetModifiers() {
    return modifiers;
}

std::vector<std::string> *sd::PlayerVocabulary::GetNavigation() {
    return navigation;
}

void sd::PlayerVocabulary::Handle(std::shared_ptr<EventArgs> _e) {
    if (_e->type == sd::EventArgs::Type::NewWordCollected)
    {
        auto e = dynamic_cast<NewWordCollectedEventArgs*>(_e.get());

        Word* word = sd::Vocabulary::allWords->Get(e->word);

        switch(word->GetType())
        {
            case (sd::Word::type::action):
                AddAction(e->word);
                break;
            case (sd::Word::type::modifier):
                AddModifier(e->word);
                break;
            case (sd::Word::type::navigation):
                AddNavigation(e->word);
                break;
        }


        std::shared_ptr<PlayerVocabChangedEventArgs> args;
        args = std::make_shared<PlayerVocabChangedEventArgs>(PlayerVocabChangedEventArgs(this));
        EventSystem::Get().Trigger(args);
    }
}
