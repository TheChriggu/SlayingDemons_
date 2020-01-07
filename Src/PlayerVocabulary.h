//
// Created by christian.heusser on 07.01.2020.
//

#ifndef SLAYINGDEMONS_PLAYERVOCABULARY_H
#define SLAYINGDEMONS_PLAYERVOCABULARY_H
#include <iostream>
#include <vector>
#include <Event/Subscriber.h>

namespace sd {
    class PlayerVocabulary : public Subscriber{
    private:
        std::vector<std::string> *actions;
        std::vector<std::string> *modifiers;
        std::vector<std::string> *navigation;

    public:
        PlayerVocabulary();

        ~PlayerVocabulary();

        bool HasWord(std::string word);

        void AddAction(std::string action);

        void AddModifier(std::string modifier);

        void AddNavigation(std::string word);

        std::vector<std::string> *GetActions();

        std::vector<std::string> *GetModifiers();

        std::vector<std::string> *GetNavigation();

        void Handle(std::shared_ptr<EventArgs> e) override;
    };
}

#endif //SLAYINGDEMONS_PLAYERVOCABULARY_H
