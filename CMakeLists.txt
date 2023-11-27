cmake_minimum_required(VERSION 3.20)
project(cpp17)

set(CMAKE_CXX_STANDARD 17)
add_executable(cpp17 main.cpp Src/Containers/VectorQuickRemove.h Src/Containers/FilteringDuplicates.h Src/Containers/CountWords.h
        Src/Containers/TodoList.h Src/Iterators/Fibonacci.h Src/Iterators/MyIterableRange.h Src/Iterators/CstringSentinel.h
        Src/Iterators/ZipIterator.h Src/Iterators/DotProduct.h Src/Lambda/basicLambda.h Src/Lambda/consumer.h Src/Lambda/Concatenation.h
        Src/Lambda/SimpleConcat.h Src/Lambda/PredicatesConjuntion.h Src/Lambda/transform_if.h Src/Lambda/MulticallSameInput.h
        Src/Lambda/CartesianProduct.h Src/STL_Algorithms/Sorting.h)
