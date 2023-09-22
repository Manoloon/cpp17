//
// Created by Manoloon on 22/9/2023.
//

#ifndef CPP17_TODOLIST_H
#define CPP17_TODOLIST_H

#include <tuple>
#include <queue>
#include <string>
#include <iostream>

    using item_type = std::pair<int, std::string>;

    void TodoList()
    {
            std::priority_queue<item_type> PQueue;
            std::initializer_list<item_type> ActionList
            {
                { 1, "eat" },
                { 0, "Play" },
                { 2, "drink" },
                { 3, "breath" },
                { 0, "work" },
            };

            for (const auto& action : ActionList)
            {
                PQueue.push(action);
            }
            while (!PQueue.empty())
            {
                std::cout << PQueue.top().first << ": " << PQueue.top().second << std::endl;
                PQueue.pop();
            }
    }

#endif //CPP17_TODOLIST_H
