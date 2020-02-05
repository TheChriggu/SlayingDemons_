#include <memory>
#include "Application.h"

int main() {

    Sp<sd::Application> app = std::make_shared<sd::Application>();
    auto result = app->setup ();

    if (!result) {
      std::cerr << "Error while setting up Application!" << std::endl;
        return 1;
    }

    while (app->run ())
    {
    }

    app->shutdown ();
    
    /*Trie trie;
    
    auto lines = sd::FileInput::load_tsv("../Resources/Tables/Actions.tsv");
    
    for(const auto& content : *lines) {
        //std::cout << "add word: " << content[0] << std::endl;
        if (content[0] != "Name"){
            trie.add_word(content[0]);
        }
    }
    
    auto result = trie.get_all_that_starts_with("bR");
    
    for (const auto& word : *result) {
        std::cout << word << std::endl;
    }*/

    return 0;
}