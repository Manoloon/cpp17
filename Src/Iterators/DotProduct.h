//
// Created by Manoloon on 28/9/2023.
//

#ifndef CPP17_DOTPRODUCT_H
#define CPP17_DOTPRODUCT_H
#include <numeric>
#include "ZipIterator.h"

const auto AddProduct([](double sum, const auto& product){
    return sum + product.first * product.second;
});

double DotProduct(const Zipper& Zipper)
{
   return std::accumulate(std::begin(Zipper),std::end(Zipper),0.0,AddProduct);
}
#endif //CPP17_DOTPRODUCT_H
