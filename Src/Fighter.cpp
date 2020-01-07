//
// Created by christian.heusser on 28.11.2019.
//

#include "Fighter.h"
#include <iostream>

sd::Fighter::Fighter() {
    offensiveStats = new Stats();
    offensiveBuffs = new Stats();
    defensiveStats = new Stats();
    defensiveBuffs = new Stats();

    //TODO: Load stat values from file or something like that. Buffs should probably be 0
    Stats stats1 = {1,1,1,1,1,1,1,1};
    Stats stats2 = {8,7,6,5,4,3,2,1};
    StatwiseOperation ops1 = {StatwiseOperation::OperationType::Add
                              , StatwiseOperation::OperationType::Add
                              ,StatwiseOperation::OperationType::Add
                              ,StatwiseOperation::OperationType::Add
                              ,StatwiseOperation::OperationType::Add
                              ,StatwiseOperation::OperationType::Add
                              ,StatwiseOperation::OperationType::Add
                              ,StatwiseOperation::OperationType::Add
    };
    StatwiseOperation ops2 = {StatwiseOperation::OperationType::Mult
                                , StatwiseOperation::OperationType::Mult
                                ,StatwiseOperation::OperationType::Mult
                                ,StatwiseOperation::OperationType::Mult
                                ,StatwiseOperation::OperationType::Mult
                                ,StatwiseOperation::OperationType::Mult
                                ,StatwiseOperation::OperationType::Mult
                                ,StatwiseOperation::OperationType::Mult
    };


    SetBaseStats(stats1, stats2);
    //stats1 = stats1 + stats1;
    //stats2 = stats2 * stats2;
    SetBuffs(stats1,stats2);
    ChangeBuffs(stats1,ops1,stats2,ops1);

}

sd::Fighter::~Fighter() {
    delete(offensiveStats);
    delete(offensiveBuffs);
    delete(defensiveStats);
    delete(defensiveBuffs);

    offensiveStats = nullptr;
    offensiveBuffs = nullptr;
    defensiveStats = nullptr;
    defensiveBuffs = nullptr;
}

sd::Stats sd::Fighter::GetOffense() {
    return (*offensiveStats)*(*offensiveBuffs);
}

sd::Stats sd::Fighter::GetDefense() {
    return (*defensiveStats)+(*defensiveBuffs);
}

void sd::Fighter::SetBaseStats(sd::Stats offense, sd::Stats defense) {
    *offensiveStats = offense;
    *defensiveStats = defense;
}

void sd::Fighter::SetBuffs(sd::Stats offense, sd::Stats defense) {
    *offensiveBuffs = offense;
    *defensiveBuffs = defense;
}

void sd::Fighter::ChangeBaseStats(Stats offense, StatwiseOperation offenseOps, Stats defense, StatwiseOperation defenseOps) {
    *offensiveStats = offenseOps.Operate(*offensiveStats, offense);
    *defensiveStats = defenseOps.Operate(*defensiveStats, defense);
}

void sd::Fighter::ChangeBuffs(sd::Stats offense, sd::StatwiseOperation offenseOps, sd::Stats defense,sd::StatwiseOperation defenseOps) {
    *offensiveBuffs = offenseOps.Operate(*offensiveBuffs, offense);
    *defensiveBuffs = defenseOps.Operate(*defensiveBuffs, defense);
}

void sd::Fighter::PrintToConsole() {
    std::cout << "Fighter Offense: \nSpeed: " << offensiveStats->speed << "\nAccuracy: " << offensiveStats->accuracy << "\nPhysical: " << offensiveStats->physical<< "\nMental: " << offensiveStats->mental << "\nFire: " << offensiveStats->fire << "\nWater: " << offensiveStats->water << "\nTree: " << offensiveStats->tree << "\nEarth: " << offensiveStats->earth << "\n";
    std::cout << "Fighter Offensive Buffs: \nSpeed: " << offensiveBuffs->speed << "\nAccuracy: " << offensiveBuffs->accuracy << "\nPhysical: " << offensiveBuffs->physical << "\nMental: " << offensiveBuffs->mental << "\nFire: " << offensiveBuffs->fire << "\nWater: " << offensiveBuffs->water << "\nTree: " << offensiveBuffs->tree << "\nEarth: " << offensiveBuffs->earth<<"\n";
    std::cout << "Fighter Defense: \nSpeed: " << defensiveStats->speed << "\nAccuracy: " << defensiveStats->accuracy << "\nPhysical: " << defensiveStats->physical << "\nMental: " << defensiveStats->mental << "\nFire: " << defensiveStats->fire << "\nWater: " << defensiveStats->water << "\nTree: " << defensiveStats->tree << "\nEarth: " << defensiveStats->earth<< "\n";
    std::cout << "Fighter Defensive Buffs: \nSpeed: " << defensiveBuffs->speed << "\nAccuracy: " << defensiveBuffs->accuracy << "\nPhysical: " << defensiveBuffs->physical << "\nMental: " << defensiveBuffs->mental << "\nFire: " << defensiveBuffs->fire << "\nWater: " << defensiveBuffs->water << "\nTree: " << defensiveBuffs->tree << "\nEarth: " << defensiveBuffs->earth << "\n";
}

void sd::Fighter::ChangeMentalState(float value) {
    mentalState += value;
}

void sd::Fighter::ChangeHitPoints(float value) {
    hitPoints += value;
}

float sd::Fighter::GetMentalState() {
    return mentalState;
}

float sd::Fighter::GetHitPoints() {
    return hitPoints;
}
