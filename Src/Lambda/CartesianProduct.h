//
// Created by Manoloon on 9/10/2023.
//

#ifndef CPP17_CARTESIANPRODUCT_H
#define CPP17_CARTESIANPRODUCT_H

#include <iostream>

static void PrintProduct(int x, int y)
{
    std::cout << x << ", " << y << std::endl;
}

constexpr auto call_cartesian([](auto f, auto x, auto ...rest) constexpr
                              {
                                  (void) std::initializer_list<int>{
                                          (((x < rest) ?
                                            (void) f(x, rest) :
                                            (void) 0), 0)...
                                  };
                              });

constexpr auto cartesian([](auto ...xs) constexpr
                         {
                             return [=](auto f) constexpr
                             {
                                 (void) std::initializer_list<int>{
                                         ((void) call_cartesian(f, xs, xs...), 0)...
                                 };
                             };
                         });

#endif //CPP17_CARTESIANPRODUCT_H
