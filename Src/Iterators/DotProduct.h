//
// Created by Manoloon on 28/9/2023.
//

#ifndef CPP17_DOTPRODUCT_H
#define CPP17_DOTPRODUCT_H
#include <numeric>
#include "ZipIterator.h"

/*
    std::vector<double> a {1.0,2.0,3.0};
    std::vector<double> b {4.0,5.0,6.0};
    Zipper zipped(a,b);
    std::cout << DotProduct(zipped);
 */

const auto AddProduct([](double sum, const auto& product){
    return sum + product.first * product.second;
});

double DotProduct(const Zipper& Zipper)
{
   return std::accumulate(std::begin(Zipper),std::end(Zipper),0.0,AddProduct);
}
#endif //CPP17_DOTPRODUCT_H
