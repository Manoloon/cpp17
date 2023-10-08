//
// Created by Manoloon on 8/10/2023.
//

#ifndef CPP17_MULTICALLSAMEINPUT_H
#define CPP17_MULTICALLSAMEINPUT_H
/*
 *
    auto f (brace_print('(',')'));
    auto g (brace_print('[',']'));
    auto h (brace_print('<','>'));
    auto nl ([](auto){std::cout << std::endl;});

    auto call_fgh(multicall(f,g,h,nl));
    for_each(call_fgh,1,2,3,4,5);
 */
#include <iostream>

template<typename ...FUNCTIONS>
static auto multicall(FUNCTIONS ...functions)
{
    return [=](auto x)
    {
        (void) std::initializer_list<int>{
                ((void) functions(x), 0)...
        };
    };
}

template<typename F,typename ...XS>
static auto for_each(F f, XS ...xs)
{
    (void) std::initializer_list<int>{
            ((void) f(xs), 0)...
    };
}

static auto brace_print(char a, char b)
{
    return [=](auto x)
    {
        std::cout << a << x << b << ", ";
    };
}

#endif //CPP17_MULTICALLSAMEINPUT_H
