#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "Src/Iterators/MyIterableRange.h"
#include "Src/Iterators/Fibonacci.h"
#include "Src/Iterators/ZipIterator.h"
#include "Src/Iterators/DotProduct.h"

int main()
{
    num_range r {100,110};
    auto [min_it,max_it](std::minmax_element(std::begin(r), std::end(r)));
    std::cout << *min_it << "-" << *max_it << std::endl;
    for(size_t i : r)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
    Fibit(10);
    for(size_t i : FibRange(10))
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    // ----------------------------------- //
    std::vector<double> a {1.0,2.0,3.0};
    std::vector<double> b {4.0,5.0,6.0};
    Zipper zipped(a,b);
    std::cout << DotProduct(zipped);
        return 0;
}
