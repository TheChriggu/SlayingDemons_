//
// Created by felix on 06.01.20.
//

#ifndef SLAYINGDEMONS_EVENTARGS_H
#define SLAYINGDEMONS_EVENTARGS_H


namespace sd {
    class EventArgs {
    public:
        enum class Type {
            None = 0
        };

        EventArgs();
        virtual ~EventArgs() = default;

    protected:
        Type type_;
    };
}


#endif //SLAYINGDEMONS_EVENTARGS_H
