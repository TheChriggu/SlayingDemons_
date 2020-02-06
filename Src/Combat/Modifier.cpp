//
// Created by christian.heusser on 28.11.2019.
//

#include "Modifier.h"

sd::Modifier::Modifier(std::vector<std::string> line)
    :name_(line[0])
    ,adjective_(line[17])
    ,adverbial_(line[18])
    ,material_(line[19])
{
    stats_ = std::make_shared<Stats>();
    statwise_operation_ = std::make_shared<StatwiseOperation>();

    Stats stats = {stof(line[2])
                   ,stof(line[4])
                   ,stof(line[6])
                   ,stof(line[8])
                   ,stof(line[10])
                   ,stof(line[12])
                   ,stof(line[14])
                   ,stof(line[16])
    };

    StatwiseOperation stat_ops;
    stat_ops.speed = stat_ops.from_string(line[1]);
    stat_ops.accuracy = stat_ops.from_string(line[3]);
    stat_ops.physical = stat_ops.from_string(line[5]);
    stat_ops.mental = stat_ops.from_string(line[7]);
    stat_ops.fire = stat_ops.from_string(line[9]);
    stat_ops.water = stat_ops.from_string(line[11]);
    stat_ops.tree = stat_ops.from_string(line[13]);
    stat_ops.earth = stat_ops.from_string(line[15]);

    set_stats(stats, stat_ops);
}

void sd::Modifier::set_stats(sd::Stats stats, sd::StatwiseOperation statwise_operation) {
    *stats_ = stats;
    *statwise_operation_ = statwise_operation;
}

sd::Stats sd::Modifier::apply_to(const Sp<sd::Stats>& stats) {
    return statwise_operation_->operate(*stats, *stats_);;
}

std::string sd::Modifier::get_name() {
    return name_;
}

sd::Word::Type sd::Modifier::get_type() {
    return Type::MODIFIER;
}

std::string sd::Modifier::get_adjective() {
    return adjective_;
}

std::string sd::Modifier::get_adverbial() {
    return adverbial_;
}

std::string sd::Modifier::get_material() {
    return material_;
}
