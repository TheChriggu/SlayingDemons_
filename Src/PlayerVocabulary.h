//
// Created by christian.heusser on 07.01.2020.
//

#ifndef _PLAYERVOCABULARY_H_
#define _PLAYERVOCABULARY_H_

#include <iostream>
#include <vector>
#include <Event/Subscriber.h>
#include "Trie.h"

namespace sd {
    class PlayerVocabulary : public Subscriber{
    private:
        std::vector<std::string> actions_;
        std::vector<std::string> modifiers_;
        std::vector<std::string> commands_;
        
        Sp<Trie> actions_trie_;
        Sp<Trie> modifiers_trie_;
        Sp<Trie> commands_trie_;

    public:
        PlayerVocabulary();
        ~PlayerVocabulary() override = default;

        bool has_word(const std::string& word);

        void add_action(const std::string& action);
        void add_modifier(const std::string& modifier);
        void add_command(const std::string& word);

        std::vector<std::string>& get_actions();
        std::vector<std::string>& get_modifiers();
        std::vector<std::string>& get_commands();
    
        Sp<std::vector<std::string>> get_actions_starting_with(const std::string& prefix);
        Sp<std::vector<std::string>> get_modifiers_starting_with(const std::string& prefix);
        Sp<std::vector<std::string>> get_commands_starting_with(const std::string& prefix);

        void handle(std::shared_ptr<EventArgs> e) override;
    };
}

#endif //_PLAYERVOCABULARY_H_
