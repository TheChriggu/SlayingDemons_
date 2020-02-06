//
// Created by felix on 05.02.20.
//

#ifndef _TRIE_H_
#define _TRIE_H_

#include <string>
#include <Core/GlobalDefinitions.h>
#include <vector>
#include <map>

class Trie {
    public:
    
    Trie() = default;
    virtual ~Trie() = default;
    
    void add_word(const std::string& word);
    Sp<std::vector<std::string>> get_all();
    Sp<std::vector<std::string>> get_all_that_starts_with(const std::string& prefix);
    
    private:
    
    std::map<char, Sp<Trie>> children_;
    std::vector<std::string> complete_words_;
    
    void add_word(const std::string& sub, const std::string& orig);
};

#endif //_TRIE_H_
