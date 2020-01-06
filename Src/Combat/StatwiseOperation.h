//
// Created by christian.heusser on 06.01.2020.
//

#ifndef SLAYINGDEMONS_STATWISEOPERATION_H
#define SLAYINGDEMONS_STATWISEOPERATION_H
#include "Stats.h"
#include <iostream>

namespace sd {
    class StatwiseOperation {
    public:
        enum OperationType{Add,Mult};

        OperationType speed;
        OperationType accuracy;
        OperationType physical;
        OperationType mental;
        OperationType fire;
        OperationType water;
        OperationType tree;
        OperationType earth;

        Stats Operate(Stats a, Stats b);

        OperationType FromString(std::string strg);

    private:
        float OperateValues(float a, float b, OperationType type);
    };
}


#endif //SLAYINGDEMONS_STATWISEOPERATION_H
