//
// Created by Manoloon on 21/9/2023.
//

#ifndef CPP17_COUNTWORDS_H
#define CPP17_COUNTWORDS_H
#include <map>
#include <iomanip>
#include <string>

std::string FilterPunctuation(const std::string& s)
{
    const char *forbidden {".,:; "};
    const auto index_start(s.find_first_not_of(forbidden));
    const auto index_end(s.find_first_not_of(forbidden));

    return s.substr(index_start,index_end - (index_start + 1));
}

void CountWords()
{
    std::map<std::string,size_t> words;
    int MaxWordLength{0};
    std::string input;
    while (std::cin >> input)
    {
        std::string filtered(FilterPunctuation(input));
        MaxWordLength = std::max<int>(MaxWordLength,filtered.length());
        ++words[filtered];
    }
    std::vector<std::pair<std::string,size_t>> word_counts;
    word_counts.reserve(words.size());
    std::move(words.begin(), words.end(), std::back_inserter(word_counts));

    std::sort(std::begin(word_counts), std::end(word_counts),
              [](const auto &a,const auto &b)
              {
                  return a.second > b.second;
              });

    std::cout << "#" << std::setw(MaxWordLength) << "<WORD> " << " # <COUNT>\n";
    for(const auto & [word,count] : word_counts)
    {
        std::cout << std::setw(MaxWordLength+2) << word << " # " << count << std::endl;
    }
}

#endif //CPP17_COUNTWORDS_H
