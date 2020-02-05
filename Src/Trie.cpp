//
// Created by felix on 05.02.20.
//

#include "Trie.h"

void Trie::add_word(const std::string &word)
{
    add_word(word, word);
}

Sp<std::vector<std::string>> Trie::get_all()
{
    auto words = std::make_shared<std::vector<std::string>>();
    
    for (const auto& complete_word : complete_words_) {
        words->emplace_back(complete_word);
    }
    
    for (const auto& pair : children_) {
        auto sub_words = pair.second->get_all();
        for (const auto& word : *sub_words) {
            words->emplace_back(word);
        }
    }
    
    return words;
}

Sp<std::vector<std::string>> Trie::get_all_that_starts_with(const std::string &prefix)
{
    if (prefix.empty()) {
        return get_all();
    }
    
    char next_key = prefix[0];
    
    char next_key_lower = (char) std::tolower(next_key);
    char next_key_upper = (char) std::toupper(next_key);
    
    if (children_.count(next_key_lower) != 0) {
        return children_[next_key_lower]->get_all_that_starts_with(
            prefix.substr(1, prefix.size() - 1)
        );
    }
    if (children_.count(next_key_upper) != 0) {
        return children_[next_key_upper]->get_all_that_starts_with(
            prefix.substr(1, prefix.size() - 1)
        );
    }
    
    return std::make_shared<std::vector<std::string>>();
}

void Trie::add_word(const std::string &sub, const std::string &orig)
{
    if (sub.empty()) {
        complete_words_.emplace_back(orig);
        return;
    }
    
    char next_key = sub[0];
    
    if (children_.count(next_key) == 0) {
        children_.emplace(next_key, std::make_shared<Trie>());
    }
    
    auto new_sub = sub.substr(1, sub.size() - 1);
    
    children_[next_key]->add_word(new_sub, orig);
}
