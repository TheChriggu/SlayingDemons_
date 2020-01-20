//
// Created by christian.heusser on 09.01.2020.
//

#include <Event/LineToOutputEventArgs.h>
#include <Event/EventSystem.h>
#include "Goblin.h"

sd::Goblin::Goblin(std::string _name, int _spriteSheetIdx, sf::Vector2i _positionOnTileMap)
    : SingleTileObject(_name,_spriteSheetIdx,_positionOnTileMap, sol::function())
    {

}

void sd::Goblin::be_interacted_with() {
    if (vocab->has_word("Cyber"))
    {
        std::shared_ptr<LineToOutputEventArgs> lineArgs;
        lineArgs = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("You attack the Goblin."));
        EventSystem::Get().Trigger(lineArgs);

        std::shared_ptr<EventArgs> args;
        args = std::make_shared<EventArgs>(EventArgs());
        args->type = sd::EventArgs::Type::START_FIGHT_WITH_GOBLIN;
        EventSystem::Get().Trigger(args);
    }
    else
    {
        std::shared_ptr<LineToOutputEventArgs> args;
        args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("You're not powerful enough to fight that enemy_ yet."));
        EventSystem::Get().Trigger(args);
    }
}

void sd::Goblin::SetPlayerVocab(sd::PlayerVocabulary *_vocab) {
    vocab = _vocab;
}
