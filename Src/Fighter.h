//
// Created by christian.heusser on 28.11.2019.
//

#ifndef SLAYINGDEMONS_FIGHTER_H
#define SLAYINGDEMONS_FIGHTER_H

#include "Combat/StatwiseOperation.h"

namespace sd{
    class Fighter {
    protected:
        float hitPoints;
        float mentalState;

        Stats* offensiveStats;
        Stats* offensiveBuffs;
        Stats* defensiveStats;
        Stats* defensiveBuffs;

    public:
        Fighter();
        ~Fighter();

        Stats GetOffense();
        Stats GetDefense();

        void SetBaseStats(Stats offense, Stats defense);
        void SetBuffs(Stats offense, Stats defense);
        void ChangeBaseStats(Stats offense, StatwiseOperation offenseOps, Stats defense, StatwiseOperation defenseOps);
        void ChangeBuffs(Stats offense, StatwiseOperation offenseOps, Stats defense, StatwiseOperation defenseOps);

        void ChangeHitPoints(float value);
        void ChangeMentalState(float value);

        float GetHitPoints();
        float GetMentalState();

        void PrintToConsole();
    };
}

#endif //SLAYINGDEMONS_FIGHTER_H
