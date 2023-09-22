//
// Created by Manoloon on 19/9/2023.
//

#ifndef CPP17_FILTERINGDUPLICATES_H
#define CPP17_FILTERINGDUPLICATES_H

#include <string>
#include <set>
#include <iterator>
#include <iostream>
/*
 *  Filter duplicate words from input (Example : a a b b z hello ) or use the file words.txt
 *  std::set<std::string> StringsSet;
    FilterDuplicates(StringsSet);
 */
void FilterDuplicates(std::set<std::string>& StringsSet)
{
    // getting from user input data.
    std::istream_iterator<std::string> it(std::cin);
    std::istream_iterator<std::string> end;

    std::copy(it,end,std::inserter(StringsSet,StringsSet.end()));
    for(const auto& word : StringsSet)
    {
        std::cout << word << ",";
    }
    std::cout << std::endl;
}

#endif //CPP17_FILTERINGDUPLICATES_H
