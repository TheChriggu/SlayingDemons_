//
// Created by christian.heusser on 06.01.2020.
//

#ifndef _STATWISEOPERATION_H_
#define _STATWISEOPERATION_H_

#include "Stats.h"
#include <iostream>

namespace sd {
    class StatwiseOperation {
    public:
        enum OperationType {ADD, MULT};

        OperationType speed;
        OperationType accuracy;
        OperationType physical;
        OperationType mental;
        OperationType fire;
        OperationType water;
        OperationType tree;
        OperationType earth;

        Stats operate(Stats a, Stats b);

        OperationType from_string(const std::string& strg);

    private:
        float operate_values(float a, float b, OperationType type);
    };
}


#endif //_STATWISEOPERATION_H_
