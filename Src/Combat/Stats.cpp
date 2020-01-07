//
// Created by christian.heusser on 06.01.2020.
//

#include "Stats.h"

sd::Stats::Stats() {

}

sd::Stats::~Stats() {

}

sd::Stats sd::Stats::operator+(const sd::Stats &other) {
    sd::Stats res;
    res.speed    = speed    + other.speed   ;
    res.accuracy = accuracy + other.accuracy;
    res.physical = physical + other.physical;
    res.mental   = mental   + other.mental  ;
    res.fire     = fire     + other.fire    ;
    res.water    = water    + other.water   ;
    res.tree     = tree     + other.tree    ;
    res.earth    = earth    + other.earth   ;
    return res;
}

sd::Stats sd::Stats::operator-(const sd::Stats &other) {
    sd::Stats res;
    res.speed    = speed    - other.speed   ;
    res.accuracy = accuracy - other.accuracy;
    res.physical = physical - other.physical;
    res.mental   = mental   - other.mental  ;
    res.fire     = fire     - other.fire    ;
    res.water    = water    - other.water   ;
    res.tree     = tree     - other.tree    ;
    res.earth    = earth    - other.earth   ;
    return res;
}

sd::Stats sd::Stats::operator*(const sd::Stats &other) {
    sd::Stats res;
    res.speed    = speed    * other.speed   ;
    res.accuracy = accuracy * other.accuracy;
    res.physical = physical * other.physical;
    res.mental   = mental   * other.mental  ;
    res.fire     = fire     * other.fire    ;
    res.water    = water    * other.water   ;
    res.tree     = tree     * other.tree    ;
    res.earth    = earth    * other.earth   ;
    return res;
}

sd::Stats sd::Stats::operator/(const sd::Stats &other) {
    sd::Stats res;
    res.speed    = speed    / other.speed   ;
    res.accuracy = accuracy / other.accuracy;
    res.physical = physical / other.physical;
    res.mental   = mental   / other.mental  ;
    res.fire     = fire     / other.fire    ;
    res.water    = water    / other.water   ;
    res.tree     = tree     / other.tree    ;
    res.earth    = earth    / other.earth   ;
    return res;
}

sd::Stats sd::Stats::operator=(const Stats& other)
{
    speed    = other.speed   ;
    accuracy = other.accuracy;
    physical = other.physical;
    mental   = other.mental  ;
    fire     = other.fire    ;
    water    = other.water   ;
    tree     = other.tree    ;
    earth    = other.earth   ;
    return *this;
}

sd::Stats::Stats(float _speed, float _accuracy, float _physical, float _mental, float _fire, float _water, float _tree,
                 float _earth)
                 : speed(_speed)
                 ,accuracy(_accuracy)
                 ,physical(_physical)
                 ,mental(_mental)
                 ,fire(_fire)
                 ,water(_water)
                 ,tree(_tree)
                 ,earth(_earth)
                 {}


void sd::Stats::MinToZero() {
    if (tree < 0)
    {
        tree = 0;
    }
    if (physical < 0)
    {
        physical = 0;
    }
    if (earth < 0)
    {
        earth = 0;
    }
    if (fire < 0)
    {
        fire = 0;
    }
    if (water< 0)
    {
        water = 0;
    }

}
