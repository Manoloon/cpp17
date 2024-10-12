#include <iostream>
#include "Src/STL_Algorithms/Copy.hpp"
#include "Src/STL_Algorithms/Sorting.hpp"
#include "Src/STL_Algorithms/PrefixTree.hpp"

int main()
{
    UseCopy();

    CreateAndSortVector({2,46,6,1,120,3,10});

    PrefixTree::Demo();
    return 0;
}
