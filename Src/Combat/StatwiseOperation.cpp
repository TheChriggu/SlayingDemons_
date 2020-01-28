//
// Created by christian.heusser on 06.01.2020.
//

#include "StatwiseOperation.h"

sd::Stats sd::StatwiseOperation::operate(sd::Stats a, sd::Stats b) {
    Stats retVal = {};
    retVal.speed    = operate_values(a.speed, b.speed, speed);
    retVal.accuracy = operate_values(a.accuracy, b.accuracy, accuracy);
    retVal.physical = operate_values(a.physical, b.physical, physical);
    retVal.mental   = operate_values(a.mental, b.mental, mental);
    retVal.fire     = operate_values(a.fire, b.fire, fire);
    retVal.water    = operate_values(a.water, b.water, water);
    retVal.tree     = operate_values(a.tree, b.tree, tree);
    retVal.earth    = operate_values(a.earth, b.earth, earth);
    return retVal;
}

float sd::StatwiseOperation::operate_values(float a, float b, sd::StatwiseOperation::OperationType type) {
    if (type == ADD)
    {
        return a+b;
    }
    if(type == MULT)
    {
        return a*b;
    }
    return -1000000;
}

sd::StatwiseOperation::OperationType sd::StatwiseOperation::from_string(const std::string& strg) {
    if (strg == "*")
    {
        return MULT;
    }
    return ADD;
}
