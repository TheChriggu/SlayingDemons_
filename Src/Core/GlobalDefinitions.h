//
// Created by felix on 07.01.20.
//

#ifndef _GLOBALDEFINITIONS_H_
#define _GLOBALDEFINITIONS_H_

#include <memory>

template <typename T> using Sp = std::shared_ptr<T>;
template <typename T> using Up = std::unique_ptr<T>;
template <typename T> using Wp = std::weak_ptr<T>;

#endif //_GLOBALDEFINITIONS_H_
