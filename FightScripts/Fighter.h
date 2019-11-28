//
// Created by christian.heusser on 28.11.2019.
//

#ifndef SLAYINGDEMONS_FIGHTER_H
#define SLAYINGDEMONS_FIGHTER_H

namespace sd{
    struct Stats
    {
        float speed;
        float accuracy;
        float physical;
        float mental;
        float fire;
        float water;
        float tree;
        float earth;
        float plant;

        Stats& operator +(const Stats& other)
        {
            speed    += other.speed   ;
            accuracy += other.accuracy;
            physical += other.physical;
            mental   += other.mental  ;
            fire     += other.fire    ;
            water    += other.water   ;
            tree     += other.tree    ;
            earth    += other.earth   ;
            plant    += other.plant   ;
            return *this;
        }

        Stats& operator *(const Stats& other)
        {
            speed    *= other.speed   ;
            accuracy *= other.accuracy;
            physical *= other.physical;
            mental   *= other.mental  ;
            fire     *= other.fire    ;
            water    *= other.water   ;
            tree     *= other.tree    ;
            earth    *= other.earth   ;
            plant    *= other.plant   ;
            return *this;
        }

        Stats& operator =(const Stats& other)
        {
            speed    = other.speed   ;
            accuracy = other.accuracy;
            physical = other.physical;
            mental   = other.mental  ;
            fire     = other.fire    ;
            water    = other.water   ;
            tree     = other.tree    ;
            earth    = other.earth   ;
            plant    = other.plant   ;
            return *this;
        }
    };

    struct StatwiseOperation
    {
        enum OperationType{Add,Mult};

        OperationType speed;
        OperationType accuracy;
        OperationType physical;
        OperationType mental;
        OperationType fire;
        OperationType water;
        OperationType tree;
        OperationType earth;
        OperationType plant;

        Stats Operate(Stats a, Stats b)
        {
            Stats retVal = {};
            retVal.speed    = OperateValues(a.speed,b.speed,speed);
            retVal.accuracy = OperateValues(a.accuracy,b.accuracy,accuracy);
            retVal.physical = OperateValues(a.physical,b.physical,physical);
            retVal.mental   = OperateValues(a.mental,b.mental,mental);
            retVal.fire     = OperateValues(a.fire,b.fire,fire);
            retVal.water    = OperateValues(a.water,b.water,water);
            retVal.tree     = OperateValues(a.tree,b.tree,tree);
            retVal.earth    = OperateValues(a.earth,b.earth,earth);
            retVal.plant    = OperateValues(a.plant,b.plant,plant);
            return retVal;
        }

    private:
        float OperateValues(float a, float b, OperationType type)
        {
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
    };

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

        void PrintToConsole();
    };
}

#endif //SLAYINGDEMONS_FIGHTER_H
