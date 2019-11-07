//
// Created by christian.heusser on 07.11.2019.
//

#include "FormattedLine.h"

FormattedLine::FormattedLine(sf::String string, sf::Vector2f _position) {
    words = new std::list<FormattedWord*>();
    position = _position;
    words->push_back(new FormattedWord("", false, _position));
    formatLine(string);

}

FormattedLine::~FormattedLine() {
    delete words;
    words = nullptr;
}

void FormattedLine::drawTo(sf::RenderWindow* window, sf::RenderWindow* glitchWindow) {
    for (FormattedWord* word : *words) {
        word->drawTo(window, glitchWindow);
    }
}

void FormattedLine::formatLine(sf::String string) {
    sf::String word = "";
    for(auto c = string.begin(); c != string.end(); c++)
    {
        if(sf::String(*c) != ' ')
        {
            word += *c;
        }

        else
        {
            sf::Vector2f wordPosition =  sf::Vector2f(getRect().left + getRect().width,getRect().top);
           FormattedWord* newWord = new FormattedWord(word, false, wordPosition);
           words->push_back(newWord);
           word = " ";
        }
    }

    FormattedWord* newWord = new FormattedWord(word, false, sf::Vector2f(getRect().left + getRect().width,getRect().top));
    words->push_back(newWord);
}

sf::FloatRect FormattedLine::getRect(){
    sf::FloatRect retVal = words->front()->getRect();

    for (FormattedWord* word : *words)
    {
        sf::FloatRect rect = word->getRect();
        if (rect.top < retVal.top)
        {
            retVal.top = rect.top;
        }
        if (rect.left < retVal.left)
        {
            retVal.left = rect.left;
        }
        if (rect.top + rect.height > retVal.top + retVal.height)
        {
            retVal.height = rect.top + rect.height - retVal.top;
        }
        if (rect.left + rect.width > retVal.left + retVal.width)
        {
            retVal.width = rect.left + rect.width - retVal.left;
        }
    }
    return retVal;
}

void FormattedLine::toggleGlitch() {
    for (FormattedWord* word : *words) {
        word->toggleGlitch();
    }
}

