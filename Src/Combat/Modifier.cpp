//
// Created by christian.heusser on 28.11.2019.
//

#include "Modifier.h"

sd::Modifier::Modifier() {
    stats = new Stats();
    statwiseOperation = new StatwiseOperation();

    SetStats({0,0,0,0,0,0,0,0}
    ,{StatwiseOperation::Add,StatwiseOperation::Add,StatwiseOperation::Add,StatwiseOperation::Add,StatwiseOperation::Add,StatwiseOperation::Add,StatwiseOperation::Add,StatwiseOperation::Add});
}

sd::Modifier::~Modifier() {

}

void sd::Modifier::LoadFrom(sf::String source) {

}

void sd::Modifier::SetStats(sd::Stats _stats, sd::StatwiseOperation _statwiseOperation) {
    *stats = _stats;
    *statwiseOperation = _statwiseOperation;
}

sd::Stats sd::Modifier::ApplyTo(sd::Stats *_stats) {
    Stats retVal = statwiseOperation->Operate(*_stats, *stats);
    return retVal;
}

void sd::Modifier::SetName(sf::String _name) {
    name = _name;
}

sf::String sd::Modifier::GetName() {
    return name;
}

sd::Word::type sd::Modifier::GetType() {
    return modifier;
}
