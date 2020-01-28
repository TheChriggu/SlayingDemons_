//
// Created by christian.heusser on 06.01.2020.
//

#ifndef _STATS_H_
#define _STATS_H_
#include <iostream>

namespace sd {
    class Stats {
    public:
        float speed;
        float accuracy;
        float physical;
        float mental;
        float fire;
        float water;
        float tree;
        float earth;
        
        enum class SingleStatType{
            PHYSICAL,
            MENTAL,
            FIRE,
            WATER,
            TREE,
            EARTH
        };
        
        struct SingleStat{
            float value;
            SingleStatType type;
        };

        Stats() = default;
        Stats(float speed, float accuracy, float physical, float mental, float fire, float water, float tree
                , float earth);
        virtual ~Stats() = default;

        Stats operator+(const Stats &other);
        Stats operator-(const Stats &other);
        Stats operator*(const Stats &other);
        Stats operator/(const Stats &other);
        Stats operator=(const Stats &other);

        void min_to_zero();
        SingleStat get_max_damage_stat();
        static std::string stat_type_to_string(SingleStatType type);
    };
}

#endif //_STATS_H_
