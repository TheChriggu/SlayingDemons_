//
// Created by christian.heusser on 06.01.2020.
//

#ifndef SLAYINGDEMONS_STATS_H
#define SLAYINGDEMONS_STATS_H
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

        Stats();
        Stats(float speed, float accuracy, float physical, float mental, float fire, float water, float tree
                , float earth);
        ~Stats();

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

#endif //SLAYINGDEMONS_STATS_H
