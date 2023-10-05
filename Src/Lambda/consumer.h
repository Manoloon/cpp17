//
// Created by Manoloon on 4/10/2023.
//

#ifndef CPP17_CONSUMER_H
#define CPP17_CONSUMER_H

#include <deque>
#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>
#include <functional>
namespace Consumer
{
//Helpers
    template<typename T>
    static auto Consumer(T &Container)
    {
        return [&](auto value)
        {
            Container.push_back(value);
        };
    }

    template<typename T>
    static void print(const T &c)
    {
        for (auto i: c) {
            std::cout << i << ", ";
        }
        std::cout << std::endl;
    }

/*------------------*/
    void FeedConsumers(int number)
    {
        if (number < 1) {
            throw std::domain_error("number should be at least 1");
        }
        std::deque<int> d;
        std::list<int> l;
        std::vector<int> v;
        const std::vector<std::function<void(int)>> consumers{Consumer(d), Consumer(l),
                                                              Consumer(v)};
        for (int i = 0; i < number; ++i) {
            for (auto &&consume: consumers) {
                consume(i);
            }
        }
        print(d);
        print(l);
        print(v);
    }
}
#endif //CPP17_CONSUMER_H
