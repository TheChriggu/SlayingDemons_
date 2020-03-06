//
// Created by christian.heusser on 28.11.2019.
//

#ifndef _FIGHTER_H_
#define _FIGHTER_H_

#include <Core/GlobalDefinitions.h>
#include "Combat/StatwiseOperation.h"

namespace sd{
    class Fighter {
    protected:
        float hit_points_;

        Sp<Stats> offensive_stats_;
        Sp<Stats> defensive_stats_;;

    public:
        Fighter();
        virtual ~Fighter() = default;

        Stats get_offense();
        Stats get_defense();

        void set_base_stats(const Stats& offense, const Stats& defense);
        void change_base_stats(const Stats& offense, StatwiseOperation offense_ops, const Stats& defense, StatwiseOperation defense_ops);

        void change_hit_points(float value);
        void set_hit_points(float value);

        float get_hit_points();

        void print_to_console();
    };
}

#endif //_FIGHTER_H_
