//
// Created by Manoloon on 8/10/2023.
//

#ifndef CPP17_TRANSFORM_IF_H
#define CPP17_TRANSFORM_IF_H
#include <iostream>
#include <iterator>
#include <numeric>

//Helpers
template<typename T>
auto map(T fn){
   return [=](auto reduce_fn)
   {
       return [=](auto accum,auto input){
           return reduce_fn(accum,fn(input));
       };
   };
}

template<typename T>
auto filter(T predicate){
    return [=](auto reduce_fn){
        return [=](auto accum,auto input){
            if(predicate(input)){
                return reduce_fn(accum,input);
            } else{
                return accum;
            }
        };
    };
}

    auto copy_and_advance([](auto it,auto input){
        *it = input;
        return ++it;
    });

    auto even ([](int i){return i %2 ==0;});
    auto twice ([](int i){return i * 2;});

    //Implementation
    void FindEvenNumbersAndDoubled()
    {
        std::istream_iterator<int> it (std::cin);
        std::istream_iterator<int> end_it;
        std::accumulate(it,end_it,
                        std::ostream_iterator<int>{std::cout, ", "},
                        filter(even)(map(twice)(copy_and_advance)
                        ));
    }
#endif //CPP17_TRANSFORM_IF_H
