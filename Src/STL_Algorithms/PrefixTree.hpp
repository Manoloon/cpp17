#pragma once
/*
    A Prefix tree made only with STL Data Structures and Algorithms
*/
#include <map>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <string>
#include <optional>

template<typename T>
class Trie
{
    std::map<T,Trie> Tries;

    public:
    template<typename it>
    void Insert(it begin_it, it end_it)
    {
        if(begin_it == end_it) return;
        Tries[*begin_it].Insert(std::next(begin_it),end_it);
    }
    
    template<typename C>
    void Insert(const C& container)
    {
        Insert(std::begin(container),std::end(container));
    }
    
    void Insert(const std::initializer_list<T>& initList)
    {
        Insert(std::begin(initList),std::end(initList));
    }
    
    template<typename It>
    std::optional<std::reference_wrapper<const Trie>>
    SubTrie(It it,It end_it) const 
    {
        if(it == end_it) return std::ref(*this);
        auto Found(Tries.find(*it));
        if(Found == std::end(Tries)) return {};

        return Found->second.SubTrie(std::next(it),end_it);
    }

    template<typename C>
    auto SubTrie(const C& container)
    {
        return SubTrie(std::begin(container),std::end(container));
    }

    void Print() const
    {
        std::vector<T> vec;
        Print(vec);
    }

private :
    void Print(std::vector<T>& vec) const 
    {
        if (Tries.empty())
        {
            std::copy(std::begin(vec),std::end(vec),
                std::ostream_iterator<T>{std::cout, " "});
            std::cout << '\n';
        }
        for(const auto& t : Tries)
        {
            vec.emplace_back(t.first);
            t.second.Print(vec);
            vec.pop_back();
        }
    }
};

namespace PrefixTree
{
    void Demo()
    {
        Trie<std::string> trie;
        trie.Insert({"hi","how","are","you"});
        trie.Insert({"hi","fine","and","you"});
        trie.Insert({"what","are","you","doing"});
        trie.Insert({"i","am","playing","games"});
        std::cout << "Demo for tries: \n";
        trie.Print();
        std::cout << "\nPossible suggestions after \"hi\":\n";
        if(auto st(trie.SubTrie(std::initializer_list<std::string>{"hi"}));
            st)
            {
                st->get().Print();
            }
    }
}