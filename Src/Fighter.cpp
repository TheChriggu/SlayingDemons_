// Created by christian.heusser on 28.11.2019.
//

#include "Fighter.h"
#include <iostream>

sd::Fighter::Fighter() {
    hit_points_ = 1;


    offensive_stats_ = std::make_shared<Stats>();
    defensive_stats_ = std::make_shared<Stats>();

    Stats stats = {0,0,0,0,0,0,0,0};
    set_base_stats(stats, stats);
}

sd::Stats sd::Fighter::get_offense() {
    return (*offensive_stats_);
}

sd::Stats sd::Fighter::get_defense() {
    return (*defensive_stats_);
}

void sd::Fighter::set_base_stats(const sd::Stats& offense, const sd::Stats& defense) {
    *offensive_stats_ = offense;
    *defensive_stats_ = defense;
}

void sd::Fighter::change_base_stats(const Stats& offense, StatwiseOperation offense_ops, const Stats& defense, StatwiseOperation defense_ops) {
    *offensive_stats_ = offense_ops.operate(*offensive_stats_, offense);
    *defensive_stats_ = defense_ops.operate(*defensive_stats_, defense);
}


void sd::Fighter::print_to_console() {
    std::cout << "Fighter Offense: \nSpeed: " << offensive_stats_->speed << "\nAccuracy: " << offensive_stats_->accuracy << "\nPhysical: " << offensive_stats_->physical << "\nMental: " << offensive_stats_->mental << "\nFire: " << offensive_stats_->fire << "\nWater: " << offensive_stats_->water << "\nTree: " << offensive_stats_->tree << "\nEarth: " << offensive_stats_->earth << "\n";
    std::cout << "Fighter Defense: \nSpeed: " << defensive_stats_->speed << "\nAccuracy: " << defensive_stats_->accuracy << "\nPhysical: " << defensive_stats_->physical << "\nMental: " << defensive_stats_->mental << "\nFire: " << defensive_stats_->fire << "\nWater: " << defensive_stats_->water << "\nTree: " << defensive_stats_->tree << "\nEarth: " << defensive_stats_->earth << "\n";
}

void sd::Fighter::change_hit_points(float value) {
    hit_points_ += value;
}

float sd::Fighter::get_hit_points() {
    return hit_points_;
}

