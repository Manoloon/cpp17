//
// Created by Manoloon on 6/10/2023.
//

#ifndef CPP17_CONCATENATION_H
#define CPP17_CONCATENATION_H

#include <iostream>
#include <functional>

template<typename T, typename ...Ts>
auto concat(T t, Ts...ts)
{
    if constexpr(sizeof ...(ts) > 0)
    {
        return [=](auto ...parameters)
        {
            return t(concat(ts...)(parameters...));
        };
    }
    else
    {
        return t;
    }
}

auto const Twice ([](int i){return i * 2;});
auto const Thrice ([](int i){return i * 3;});
auto const combined(concat(Twice,Thrice,std::plus<int>{}));
#endif //CPP17_CONCATENATION_H
