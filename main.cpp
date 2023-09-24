#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include <map>
#include <iomanip>
#include "Src/Itearators/MyIterableRange.h"
#include "Src/Itearators//Fibonacci.h"

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
        return 0;
}
