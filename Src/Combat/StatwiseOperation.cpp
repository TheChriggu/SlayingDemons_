//
// Created by christian.heusser on 06.01.2020.
//

#include "StatwiseOperation.h"

sd::Stats sd::StatwiseOperation::Operate(sd::Stats a, sd::Stats b) {
    Stats retVal = {};
    retVal.speed    = OperateValues(a.speed,b.speed,speed);
    retVal.accuracy = OperateValues(a.accuracy,b.accuracy,accuracy);
    retVal.physical = OperateValues(a.physical,b.physical,physical);
    retVal.mental   = OperateValues(a.mental,b.mental,mental);
    retVal.fire     = OperateValues(a.fire,b.fire,fire);
    retVal.water    = OperateValues(a.water,b.water,water);
    retVal.tree     = OperateValues(a.tree,b.tree,tree);
    retVal.earth    = OperateValues(a.earth,b.earth,earth);
    return retVal;
}

float sd::StatwiseOperation::OperateValues(float a, float b, sd::StatwiseOperation::OperationType type) {
    if (type == Add)
    {
        return a+b;
    }
    if(type == Mult)
    {
        return a*b;
    }
    return -1000000;
}

sd::StatwiseOperation::OperationType sd::StatwiseOperation::FromString(std::string strg) {
    if (strg == "*")
    {
        return Mult;
    }
    return Add;
}
