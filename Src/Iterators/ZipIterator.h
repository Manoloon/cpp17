//
// Created by Manoloon on 27/9/2023.
//

#ifndef CPP17_ZIPITERATOR_H
#define CPP17_ZIPITERATOR_H
#include <vector>

class ZipIterator{
    using itType = std::vector<double>::iterator;
    itType it1;
    itType it2;

public:
    ZipIterator(itType iterator1, itType iterator2):it1{iterator1},it2{iterator2}{}

    ZipIterator& operator ++(){
        ++it1;
        ++it2;
        return *this;
    }
    bool operator !=(const ZipIterator& other)const {
        return it1 != other.it1 && it2 != other.it2;
    }

    bool operator ==(const ZipIterator& other)const {
        return !operator!=(other);
    }
    std::pair<double,double> operator *() const{
        return {*it1,*it2};
    }
};
template<>
struct std::iterator_traits<ZipIterator>{
    using iterator_category = std::forward_iterator_tag;
    using value_type = std::pair<double,double>;
    using difference_type = long int;
};
class Zipper{
    using vecType = std::vector<double>;
    vecType &vec1;
    vecType &vec2;

public:
    Zipper(vecType &va, vecType &vb):vec1{va},vec2{vb}{}

    ZipIterator begin() const {return {std::begin(vec1),std::begin(vec2)};}
    ZipIterator end() const {return {std::end(vec1),std::end(vec2)};}
};
#endif //CPP17_ZIPITERATOR_H
