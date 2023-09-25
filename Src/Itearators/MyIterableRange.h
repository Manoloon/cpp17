//
// Created by pablo on 24/9/2023.
//

#ifndef CPP17_MYITERABLERANGE_H
#define CPP17_MYITERABLERANGE_H
#include <iostream>
#include <algorithm>

class num_iterator{
    int i;
public:
    explicit num_iterator(int position =0):i{position}{}

    int operator *() const {return i;}
    num_iterator& operator ++(){
        ++i;
        return *this;
    }
    bool operator !=(const num_iterator& other)const {return i != other.i;}

    bool operator ==(const num_iterator& other)const {return !(*this != other);}
};

template<>
struct std::iterator_traits<num_iterator>{
    using iterator_category = std::forward_iterator_tag;
    using value_type = int;
};

class num_range{
    int a;
    int b;
public:
    num_range(int from, int to): a{from},b{to}{}
    num_iterator begin() const {return num_iterator{a};}
    num_iterator end() const {return num_iterator{b};}
};
#endif //CPP17_MYITERABLERANGE_H
