//
// Created by felix on 26.11.19.
//

#ifndef _MANAGEABLE_H_
#define _MANAGEABLE_H_

class Manageable {
public:
    // declare virtual destructor to avoid potential memory leaks
    virtual ~Manageable() = default;

    virtual bool setup() = 0;
    virtual void shutdown() = 0;

protected:
    bool is_setup_{};
};

#endif //_MANAGEABLE_H_
