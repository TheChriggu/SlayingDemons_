//
// Created by christian.heusser on 07.01.2020.
//

#include <Event/PlayerVocabChangedEventArgs.h>
#include <Event/PlayerStateCreatedEventArgs.h>
#include <Event/FontsCreatedEventArgs.h>
#include <Event/ColorsCreatedEventArgs.h>
#include <Event/PossibleWordsCreatedEventArgs.h>
#include <Event/EventSystem.h>
#include <ScriptEngine/ScriptEngine.h>
#include <regex>
#include <InputTextProcessor.h>
#include "PossibleWords.h"
#include "Event/SetStageEventArgs.h"

// TODO(FK): clean up name
sd::PossibleWords::PossibleWords(sf::Vector2f position, sf::Vector2f size)
    : DrawableObject("possible-words")
    , Subscriber()
    , position_(position)
    , size_(size)
    , current_list_type_(Word::Type::COMMAND)
    , loop_iterator_(0)
{
    event_handler_ = CREATE_EVENT_HANDLER(
        if (e->type == sd::EventArgs::Type::FIGHT_STARTED) {
            display_modifiers();
            set_search_prefix("");
        
        }
        if (e->type == sd::EventArgs::Type::FIGHT_ENDED) {
            display_commands();
            set_search_prefix("");
        }
    
        if (e->type == sd::EventArgs::Type::PLAYER_STATE_CREATED) {
            auto args = std::dynamic_pointer_cast<PlayerStateCreatedEventArgs>(e);
    
            player_state_ = Sp<PlayerState>(args->player_state);
            player_vocabulary_ = player_state_->get_player_vocabulary();
            
        
            std::cout << "~~Words: " << std::endl;
            for (const auto& word : player_vocabulary_->get_modifiers())
                std::cout << "~" << word << std::endl;
        
            update (player_vocabulary_->get_commands());
        }
    
        if (e->type == EventArgs::Type::FONTS_CREATED) {
            auto arg = std::dynamic_pointer_cast<FontsCreatedEventArgs>(e);
            fonts_ = Sp<Font>(arg->fonts);
        }
        if (e->type == EventArgs::Type::COLORS_CREATED) {
            auto arg = std::dynamic_pointer_cast<ColorsCreatedEventArgs>(e);
            colors_ = Sp<Colors>(arg->colors);
        }
        if (e->type == EventArgs::Type::SET_STAGE) {
            auto arg = std::dynamic_pointer_cast<SetStageEventArgs>(e);
            auto path = "../Resources/Sprites/Progressing/input_" + std::to_string(arg->stage) + ".png";
            texture_->loadFromFile(path);
        }
         if(e->type == EventArgs::Type::SET_STAGE) {
             for(auto line : lines_)
             {
                 line->set_font_size_color(fonts_, 24, colors_);
             }
         }
        );
    
    REGISTER_EVENT_HANDLER();
    
    sprite_ = std::make_shared<sf::Sprite>();
    texture_ = std::make_shared<sf::Texture>();
    search_prefix_ = "";
    possible_words_tex_ = std::make_shared<sf::RenderTexture>();
    possible_words_sprite_ = std::make_shared<sf::Sprite>();
}

bool sd::PossibleWords::setup() {

    texture_->loadFromFile("../Resources/Sprites/Progressing/input_0.png");
    sprite_->setTexture(*texture_, false);
    sprite_->setPosition(position_);
    
    
    auto event = std::make_shared<PossibleWordsCreatedEventArgs>(shared_from_this());
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
    auto save_copy = lines_;
    for(auto line : save_copy)
    {
        int i= 0;

        line->handle(event);
    }
}

void sd::PossibleWords::update(std::vector<std::string>& content) {
    possible_words_ = content;
    
    lines_.clear();
    //std::cout << "Size: " << search_prefix_.size() << std::endl;
    
    sf::Vector2f offset = sf::Vector2f(50, 90);
        
    for(const auto& word : content)
    {
        lines_.push_back(std::make_shared<FormattedLine>(
                "[button=" + word + "]" + word + "[/button]",
                sf::Vector2f(position_ + offset),
                sf::Vector2f(1000,1000),
                        fonts_, colors_));
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
}

void sd::PossibleWords::display_commands()
{
    current_list_type_ = Word::Type::COMMAND;
    update(player_vocabulary_->get_commands());
}

void sd::PossibleWords::display_objects()
{
    current_list_type_ = Word::Type::OBJECT;
    update(player_vocabulary_->get_objects());
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
        case Word::Type::OBJECT:
            update(*(player_vocabulary_->get_objects_starting_with(prefix)));
            break;
    }
}

void sd::PossibleWords::update_search_prefix(const std::string &input)
{
    set_search_prefix(std::regex_replace(input, InputTextProcessor::autocomplete_replace_pattern, ""));
}

sd::Word::Type sd::PossibleWords::get_current_list_type() const
{
    return current_list_type_;
}
std::string sd::PossibleWords::complete_first_possible_word() const
{
    return std::regex_replace(possible_words_[0], std::regex(search_prefix_), "");
}

std::string sd::PossibleWords::loop_through_possible_words()
{
    if (loop_iterator_ >= possible_words_.size())
        loop_iterator_ = 0;
    
    auto ret_val = std::regex_replace(possible_words_[loop_iterator_], std::regex(search_prefix_), "");
    loop_iterator_++;
    
    return ret_val;
}
const std::string &sd::PossibleWords::get_search_prefix() const
{
    return search_prefix_;
}




