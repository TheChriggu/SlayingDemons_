//
// Created by felix on 07.01.20.
//

#ifndef SLAYINGDEMONS_GLOBALDEFINITIONS_H
#define SLAYINGDEMONS_GLOBALDEFINITIONS_H

#include <memory>

template <typename T> using sp = std::shared_ptr<T>;
template <typename T> using up = std::unique_ptr<T>;
template <typename T> using wp = std::weak_ptr<T>;

#endif //SLAYINGDEMONS_GLOBALDEFINITIONS_H
