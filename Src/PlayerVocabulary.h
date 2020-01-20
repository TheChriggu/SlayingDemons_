//
// Created by christian.heusser on 07.01.2020.
//

#ifndef _PLAYERVOCABULARY_H_
#define _PLAYERVOCABULARY_H_

#include <iostream>
#include <vector>
#include <Event/Subscriber.h>

namespace sd {
    class PlayerVocabulary : public Subscriber{
    private:
        std::vector<std::string> *actions_;
        std::vector<std::string> *modifiers_;
        std::vector<std::string> *navigation_;

    public:
        PlayerVocabulary();

        ~PlayerVocabulary() override;

        bool has_word(std::string word);

        void add_action(std::string action);

        void add_modifier(std::string modifier);

        void add_navigation(std::string word);

        std::vector<std::string> *get_actions();

        std::vector<std::string> *GetModifiers();

        std::vector<std::string> *GetNavigation();

        void handle(std::shared_ptr<EventArgs> e) override;
    };
}

#endif //_PLAYERVOCABULARY_H_
