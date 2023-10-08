//
// Created by Manoloon on 6/10/2023.
//

#ifndef CPP17_PREDICATESCONJUNTION_H
#define CPP17_PREDICATESCONJUNTION_H
#include <string>
#include <iostream>
#include <functional>
#include <iterator>
#include <algorithm>

static bool BeginsWithA(const std::string& s)
{
    return s.find("a") ==0;
}

static bool BeginsWithB(const std::string& s)
{
    return s.find("b") == s.length() - 1;
}

template<typename A,typename B, typename F>
auto combine(F binary_func, A a,B b)
{
    return [=](auto param)
    {
        return binary_func(a(param),b(param));
    };
}

void PrintPredicate()
{
    auto a_xxx_b(combine(std::logical_and<>{},
                         BeginsWithA, BeginsWithB));

    std::copy_if(std::istream_iterator<std::string>{std::cin},{},
                 std::ostream_iterator<std::string>{std::cout, ", "},
                 a_xxx_b);
    std::cout << std::endl;
}

#endif //CPP17_PREDICATESCONJUNTION_H
