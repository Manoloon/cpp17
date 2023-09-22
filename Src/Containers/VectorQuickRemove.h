//
// Created by Manoloon on 18/9/2023.
//

#ifndef CPP17_VECTORQUICKREMOVE_H
#define CPP17_VECTORQUICKREMOVE_H
#include <iostream>
#include <vector>
#include <algorithm>

/*
 * QuickRemoveAt(vec,std::find(std::begin(vec),std::end(vec),item));
 * How to use :
 * std::vector<int> vec {123,412,1253,2000};
 * QuickRemoveAt(vec,std::find(std::begin(vec),std::end(vec),1253));
 *   for(auto i : vec)
 *   {
 *       std::cout << i << ",";
 *   }
 *   std::cout << std::endl;
 */
template<typename T>
void QuickRemoveAt(std::vector<T>&vec, std::size_t index)
{
    if(index < vec.size())
    {
        vec[index] = std::move(vec.back());
        vec.pop_back();
    }
}

template<typename T>
void QuickRemoveAt(std::vector<T>&vec,
                   typename std::vector<T>::iterator it)
{
    if(it != std::end(vec))
    {
        *it = std::move(vec.back());
        vec.pop_back();
    }
}
#endif //CPP17_VECTORQUICKREMOVE_H
