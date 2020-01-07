//
// Created by christian.heusser on 06.01.2020.
//

#ifndef SLAYINGDEMONS_STATS_H
#define SLAYINGDEMONS_STATS_H

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

        Stats();
        Stats(float speed, float accuracy, float physical, float mental, float fire, float water, float tree
                , float earth);
        ~Stats();

        Stats operator+(const Stats &other);
        Stats operator-(const Stats &other);
        Stats operator*(const Stats &other);
        Stats operator/(const Stats &other);
        Stats operator=(const Stats &other);

        void MinToZero();
    };
}

#endif //SLAYINGDEMONS_STATS_H
