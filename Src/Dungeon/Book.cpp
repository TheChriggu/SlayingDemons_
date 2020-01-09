//
// Created by christian.heusser on 08.01.2020.
//

#include <memory>
#include <Event/LineToOutputEventArgs.h>
#include <Event/EventSystem.h>
#include <Event/NewWordCollectedEventArgs.h>
#include "Book.h"

sd::Book::Book(std::string _name, int _spriteSheetIdx, sf::Vector2i _positionOnTileMap) : SingleTileObject(_name,
                                                                                                           _spriteSheetIdx,
                                                                                                           _positionOnTileMap) {

}

void sd::Book::BeInteractedWith() {
    std::shared_ptr<LineToOutputEventArgs> args;
    args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("The book is much lighter than you first thought."));
    EventSystem::Get().Trigger(args);

    args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("The paper nearly crumbles between you fingers as you try to open it."));
    EventSystem::Get().Trigger(args);

    args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("The book is pretty fragile. I should be really careful with-..."));
    EventSystem::Get().Trigger(args);

    args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("As you carefuly open the book a bit more it swings open with a loud creaking noise."));
    EventSystem::Get().Trigger(args);

    args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("You stare at it in suprise as the page began to shimmer. Over both pages are written the word \"cyber\"."));
    EventSystem::Get().Trigger(args);

    args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("Slowly you lift your hand to touch the word and as as your fingers touch the paper the word \"cyber\" faded. Still not sure what happend you look around the room."));
    EventSystem::Get().Trigger(args);

    args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("You seem to realize that the numbers and signs on the bookshelves aren't just numbers and signs. They are more like informations about people, "));
    EventSystem::Get().Trigger(args);

    args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("names, different dates and other preferences. Nevertheless you still don't have any clue what is going on here, but you get the feeling that it all makes sense...somehow."));
    EventSystem::Get().Trigger(args);

    args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("Congratulation! you collected the word \"Cyber\"."));
    EventSystem::Get().Trigger(args);

    std::shared_ptr<NewWordCollectedEventArgs> wordArgs;
    wordArgs = std::make_shared<NewWordCollectedEventArgs>("Cyber");
    EventSystem::Get().Trigger(wordArgs);
}
