//
// Created by christian.heusser on 07.01.2020.
//

#include <Event/PlayerVocabChangedEventArgs.h>
#include <Event/PlayerStateCreatedEventArgs.h>
#include <Event/FontsCreatedEventArgs.h>
#include <Event/PossibleWordsCreatedEventArgs.h>
#include <Event/EventSystem.h>
#include <ScriptEngine/ScriptEngine.h>
#include "PossibleWords.h"

// TODO(FK): clean up name
sd::PossibleWords::PossibleWords(sf::Vector2f position, sf::Vector2f size, const std::string& path_to_background)
    : DrawableObject("possible-words")
    , Subscriber()
    , position_(position)
    , size_(size)
    , current_list_type_(Word::Type::COMMAND)
{
    sprite_ = std::make_shared<sf::Sprite>();
    texture_ = std::make_shared<sf::Texture>();
    search_prefix_ = "";
    possible_words_tex_ = std::make_shared<sf::RenderTexture>();
    possible_words_sprite_ = std::make_shared<sf::Sprite>();
}

bool sd::PossibleWords::setup() {

    texture_->loadFromFile("../Resources/Sprites/fantasy_input.png");
    sprite_->setTexture(*texture_, false);
    sprite_->setPosition(position_);
    
    auto event = std::make_shared<PossibleWordsCreatedEventArgs>(this);
    EventSystem::get().trigger(event);

    auto table = ScriptEngine::get().get_script("config")->get_table("window")->as<sol::table>();
    possible_words_tex_->create(table["size"]["x"], table["size"]["y"]);
    possible_words_sprite_->setTexture(possible_words_tex_->getTexture());

    return DrawableObject::setup ();
}

void sd::PossibleWords::draw_to(Sp<sf::RenderTarget> window) const {
    possible_words_tex_->clear(sf::Color::Transparent);

    possible_words_tex_->draw(*sprite_);

    for(const auto& line : lines_)
    {
        line->draw_to (possible_words_tex_);
    }
    possible_words_tex_->display();

    if (shader_procedure_)
    {
        shader_procedure_->process (window.get (), possible_words_sprite_.get ());
    } else
    {
        window->draw(*possible_words_sprite_);
    }
}

void sd::PossibleWords::handle(sf::Event event) {

}

void sd::PossibleWords::update(std::vector<std::string>& content) {
    lines_.clear();
    //std::cout << "Size: " << search_prefix_.size() << std::endl;
    
    sf::Vector2f offset = sf::Vector2f(50, 90);
        
    for(const auto& word : content)
    {
        lines_.push_back(std::make_shared<FormattedLine>(
                word,
                sf::Vector2f(position_ + offset),
                sf::Vector2f(1000,1000),
                        fonts_));
        offset.y += 30;
    }

    /*offset = sf::Vector2f(250, 90);
    for(const auto& action : player_vocabulary_->get_actions())
    {
        lines_.push_back(std::make_shared<FormattedLine>(action,
                                                         sf::Vector2f(position_ + offset),
                                                         sf::Vector2f(1000,1000),fonts_));
            offset.y += 30;
        }
    }
    else
    {

    }*/
}

void sd::PossibleWords::handle(std::shared_ptr<EventArgs> e) {
    /*if (e->type == sd::EventArgs::Type::PLAYER_VOCAB_CHANGED) {
        auto args = std::dynamic_pointer_cast<PlayerVocabChangedEventArgs>(e);
        
        switch (args->change_type) {
            case Word::ACTION:
                update()
                break;
        }
    }*/

    if (e->type == sd::EventArgs::Type::FIGHT_STARTED) {
        display_modifiers();
        set_search_prefix("");
        
    }
    if (e->type == sd::EventArgs::Type::FIGHT_ENDED) {
        display_commands();
        set_search_prefix("");
    }
    
    if (e->type == sd::EventArgs::Type::PLAYER_STATE_CREATED) {
        auto args = dynamic_cast<PlayerStateCreatedEventArgs *>(e.get());
        
        player_vocabulary_ = args->player_state->get_player_vocabulary();
        player_state_ = Sp<PlayerState>(args->player_state);
        
        std::cout << "~~Words: " << std::endl;
        for (const auto& word : player_vocabulary_->get_modifiers())
            std::cout << "~" << word << std::endl;

        update (player_vocabulary_->get_commands());
    }

    if (e->type == EventArgs::Type::FONTS_CREATED) {
        auto arg = dynamic_cast<FontsCreatedEventArgs*>(e.get());
        fonts_ = Sp<Font>(arg->fonts);
     }
}

sf::Vector2f sd::PossibleWords::get_position() {
    return position_;
}

sf::Vector2f sd::PossibleWords::get_size() {
    return size_;
}

void sd::PossibleWords::display_modifiers()
{
    current_list_type_ = Word::Type::MODIFIER;
    update(player_vocabulary_->get_modifiers());
}

void sd::PossibleWords::display_actions()
{
    current_list_type_ = Word::Type::ACTION;
    update(player_vocabulary_->get_actions());
    //std::cout << "Size after update: " << search_prefix_.size() << std::endl;
}

void sd::PossibleWords::display_commands()
{
    current_list_type_ = Word::Type::COMMAND;
    update(player_vocabulary_->get_commands());
}

void sd::PossibleWords::set_search_prefix(const std::string &prefix)
{
    search_prefix_ = prefix;
    
    switch (current_list_type_) {
        case Word::Type::ACTION:
            update(*(player_vocabulary_->get_actions_starting_with(prefix)));
            break;
        case Word::Type::MODIFIER:
            update(*(player_vocabulary_->get_modifiers_starting_with(prefix)));
            break;
        case Word::Type::COMMAND:
            update(*(player_vocabulary_->get_commands_starting_with(prefix)));
            break;
    }
}

void sd::PossibleWords::add_to_search_prefix(const std::string &prefix)
{
    
    search_prefix_ += prefix;
    set_search_prefix(search_prefix_);
}

void sd::PossibleWords::trim_last_on_search_prefix()
{
    if (search_prefix_.empty()) return;
    
    search_prefix_.erase(search_prefix_.size() - 1, 1);
    set_search_prefix(search_prefix_);
}

const std::string &sd::PossibleWords::get_search_prefix() const
{
    return search_prefix_;
}
sd::Word::Type sd::PossibleWords::get_current_list_type() const
{
    return current_list_type_;
}



