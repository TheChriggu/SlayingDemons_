//
// Created by christian.heusser on 28.11.2019.
//

#include "Modifier.h"

sd::Modifier::Modifier() {
    stats_ = std::make_shared<Stats>();
    statwise_operation_ = std::make_shared<StatwiseOperation>();
    
    set_stats({0, 0, 0, 0, 0, 0, 0, 0}, {StatwiseOperation::ADD, StatwiseOperation::ADD, StatwiseOperation::ADD,
        StatwiseOperation::ADD, StatwiseOperation::ADD, StatwiseOperation::ADD, StatwiseOperation::ADD,
        StatwiseOperation::ADD});
}

void sd::Modifier::load_from(std::string source) {

}

void sd::Modifier::set_stats(sd::Stats stats, sd::StatwiseOperation statwise_operation) {
    *stats_ = stats;
    *statwise_operation_ = statwise_operation;
}

sd::Stats sd::Modifier::apply_to(const Sp<sd::Stats>& stats) {
    return statwise_operation_->operate(*stats, *stats_);;
}

void sd::Modifier::set_name(const std::string& name) {
    name_ = name;
}

std::string sd::Modifier::get_name() {
    return name_;
}

sd::Word::Type sd::Modifier::get_type() {
    return MODIFIER;
}
