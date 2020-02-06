//
// Created by christian.heusser on 09.01.2020.
//

#include <Event/LineToOutputEventArgs.h>
#include <Event/EventSystem.h>

#include <utility>
#include "Goblin.h"
/*
sd::Goblin::Goblin(std::string name, int sprite_sheet_idx, sf::Vector2i position_on_tile_map)
    : SingleTileObject(std::move(name), sprite_sheet_idx, position_on_tile_map, sol::function(), sol::function(), sol::function(), sol::function(), sol::function())
{
}

void sd::Goblin::be_interacted_with() {
    if (vocab_->has_word("Cyber"))
    {
        std::shared_ptr<LineToOutputEventArgs> line_args;
        line_args = std::make_shared<LineToOutputEventArgs>("You attack the Goblin.");
        EventSystem::get().trigger(line_args);

        std::shared_ptr<EventArgs> args;
        args = std::make_shared<EventArgs>(EventArgs());
        args->type = sd::EventArgs::Type::START_FIGHT_WITH_GOBLIN;
        EventSystem::get().trigger(args);
    }
    else
    {
        std::shared_ptr<LineToOutputEventArgs> args;
        args = std::make_shared<LineToOutputEventArgs>("You're not powerful enough to fight that enemy_ yet.");
        EventSystem::get().trigger(args);
    }
}

void sd::Goblin::set_player_vocab(Sp<sd::PlayerVocabulary> vocab) {
    vocab_ = std::move(vocab);
}
*/