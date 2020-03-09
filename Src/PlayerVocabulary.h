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
        std::vector<std::string> objects_;
        
        Sp<Trie> actions_trie_;
        Sp<Trie> modifiers_trie_;
        Sp<Trie> commands_trie_;
        Sp<Trie> objects_trie_;

    public:
        PlayerVocabulary();
        ~PlayerVocabulary() override = default;

        bool has_word(const std::string& word);
        bool has_action(const std::string& word);
        bool has_modifier(const std::string& word);
        bool has_command(const std::string& word);

        void add_action(std::string action);
        void add_modifier(std::string modifier);
        void add_command(std::string word);
        void set_objects(std::vector<std::string> objects);

        std::vector<std::string>& get_actions();
        std::vector<std::string>& get_modifiers();
        std::vector<std::string>& get_commands();
        std::vector<std::string>& get_objects();
    
        Sp<std::vector<std::string>> get_actions_starting_with(const std::string& prefix);
        Sp<std::vector<std::string>> get_modifiers_starting_with(const std::string& prefix);
        Sp<std::vector<std::string>> get_commands_starting_with(const std::string& prefix);
        Sp<std::vector<std::string>> get_objects_starting_with(const std::string& prefix);

        void save_to_file();
        void load_from_file();
        void load();
        void check_for_self_destruct_added();
    };
}

#endif //_PLAYERVOCABULARY_H_
