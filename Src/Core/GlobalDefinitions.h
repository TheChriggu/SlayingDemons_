//
// Created by felix on 07.01.20.
//

#ifndef SLAYINGDEMONS_GLOBALDEFINITIONS_H
#define SLAYINGDEMONS_GLOBALDEFINITIONS_H

#include <memory>

template <typename T> using sp = std::shared_ptr<T>;
template <typename T> using up = std::unique_ptr<T>;
template <typename T> using wp = std::weak_ptr<T>;

template <typename T> using make_sp = std::make_shared<T>;
template <typename T> using make_up = std::make_unique<T>;

#endif //SLAYINGDEMONS_GLOBALDEFINITIONS_H
