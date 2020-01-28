// Created by christian.heusser on 28.11.2019.
//

#include "Fighter.h"
#include <iostream>

sd::Fighter::Fighter() {
    offensive_stats_ = std::make_shared<Stats>();
    offensive_buffs_ = std::make_shared<Stats>();
    defensive_stats_ = std::make_shared<Stats>();
    defensive_buffs_ = std::make_shared<Stats>();

    //TODO: Load stat values from file or something like that. Buffs should probably be 0
    Stats stats_1 = {1,1,1,1,1,1,1,1};
    Stats stats_2 = {8,7,6,5,4,3,2,1};
    StatwiseOperation ops_1 = {StatwiseOperation::OperationType::ADD
                              , StatwiseOperation::OperationType::ADD
                              ,StatwiseOperation::OperationType::ADD
                              ,StatwiseOperation::OperationType::ADD
                              ,StatwiseOperation::OperationType::ADD
                              ,StatwiseOperation::OperationType::ADD
                              ,StatwiseOperation::OperationType::ADD
                              ,StatwiseOperation::OperationType::ADD
    };
    StatwiseOperation ops_2 = {StatwiseOperation::OperationType::MULT
                                , StatwiseOperation::OperationType::MULT
                                ,StatwiseOperation::OperationType::MULT
                                ,StatwiseOperation::OperationType::MULT
                                ,StatwiseOperation::OperationType::MULT
                                ,StatwiseOperation::OperationType::MULT
                                ,StatwiseOperation::OperationType::MULT
                                ,StatwiseOperation::OperationType::MULT
    };
    
    set_base_stats(stats_1, stats_2);
    //stats1 = stats1 + stats1;
    //stats2 = stats2 * stats2;
    set_buffs(stats_1, stats_2);
    change_buffs(stats_1, ops_1, stats_2, ops_1);

}

sd::Stats sd::Fighter::get_offense() {
    return (*offensive_stats_);//*(*offensiveBuffs);
}

sd::Stats sd::Fighter::get_defense() {
    return (*defensive_stats_);//+(*defensive_buffs_);
}

void sd::Fighter::set_base_stats(const sd::Stats& offense, const sd::Stats& defense) {
    *offensive_stats_ = offense;
    *defensive_stats_ = defense;
}

void sd::Fighter::set_buffs(const sd::Stats& offense, const sd::Stats& defense) {
    *offensive_buffs_ = offense;
    *defensive_buffs_ = defense;
}

void sd::Fighter::change_base_stats(const Stats& offense, StatwiseOperation offense_ops, const Stats& defense, StatwiseOperation defense_ops) {
    *offensive_stats_ = offense_ops.operate(*offensive_stats_, offense);
    *defensive_stats_ = defense_ops.operate(*defensive_stats_, defense);
}

void sd::Fighter::change_buffs(const sd::Stats& offense, sd::StatwiseOperation offense_ops, const sd::Stats& defense, sd::StatwiseOperation defense_ops) {
    *offensive_buffs_ = offense_ops.operate(*offensive_buffs_, offense);
    *defensive_buffs_ = defense_ops.operate(*defensive_buffs_, defense);
}

void sd::Fighter::print_to_console() {
    std::cout << "Fighter Offense: \nSpeed: " << offensive_stats_->speed << "\nAccuracy: " << offensive_stats_->accuracy << "\nPhysical: " << offensive_stats_->physical << "\nMental: " << offensive_stats_->mental << "\nFire: " << offensive_stats_->fire << "\nWater: " << offensive_stats_->water << "\nTree: " << offensive_stats_->tree << "\nEarth: " << offensive_stats_->earth << "\n";
    std::cout << "Fighter Offensive Buffs: \nSpeed: " << offensive_buffs_->speed << "\nAccuracy: " << offensive_buffs_->accuracy << "\nPhysical: " << offensive_buffs_->physical << "\nMental: " << offensive_buffs_->mental << "\nFire: " << offensive_buffs_->fire << "\nWater: " << offensive_buffs_->water << "\nTree: " << offensive_buffs_->tree << "\nEarth: " << offensive_buffs_->earth << "\n";
    std::cout << "Fighter Defense: \nSpeed: " << defensive_stats_->speed << "\nAccuracy: " << defensive_stats_->accuracy << "\nPhysical: " << defensive_stats_->physical << "\nMental: " << defensive_stats_->mental << "\nFire: " << defensive_stats_->fire << "\nWater: " << defensive_stats_->water << "\nTree: " << defensive_stats_->tree << "\nEarth: " << defensive_stats_->earth << "\n";
    std::cout << "Fighter Defensive Buffs: \nSpeed: " << defensive_buffs_->speed << "\nAccuracy: " << defensive_buffs_->accuracy << "\nPhysical: " << defensive_buffs_->physical << "\nMental: " << defensive_buffs_->mental << "\nFire: " << defensive_buffs_->fire << "\nWater: " << defensive_buffs_->water << "\nTree: " << defensive_buffs_->tree << "\nEarth: " << defensive_buffs_->earth << "\n";
}

void sd::Fighter::change_mental_state(float value) {
    mental_state_ += value;
}

void sd::Fighter::change_hit_points(float value) {
    hit_points_ += value;
}

float sd::Fighter::get_mental_state() {
    return mental_state_;
}

float sd::Fighter::get_hit_points() {
    return hit_points_;
}
