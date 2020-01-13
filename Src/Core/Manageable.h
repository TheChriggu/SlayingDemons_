//
// Created by felix on 26.11.19.
//

#ifndef SLAYINGDEMONS_MANAGEABLE_H
#define SLAYINGDEMONS_MANAGEABLE_H

class Manageable {
public:
    // declare virtual destructor to avoid potential memory leaks
    virtual ~Manageable() = default;

    virtual bool Setup() = 0;
    virtual void Shutdown() = 0;

protected:
    bool is_setup_;
};

#endif //SLAYINGDEMONS_MANAGEABLE_H
