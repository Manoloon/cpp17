//
// Created by pablo on 24/9/2023.
//

#ifndef CPP17_FIBONACCI_H
#define CPP17_FIBONACCI_H

class Fibit {
public:
        Fibit()=default;
        explicit Fibit(size_t NewIt) : It{NewIt}{}

        size_t operator *(){return b;}
        Fibit& operator ++(){
            const size_t old_b {b};
            b +=a;
            a = old_b;
            ++It;
            return *this;
        }
        bool operator !=(const Fibit &Other) const {return It != Other.It; }
private:
        size_t It {0};
        size_t a {0};
        size_t b {1};
};

template<>
struct std::iterator_traits<Fibit>{
    using iterator_category = std::forward_iterator_tag;
    using value_type = size_t;
};

class FibRange{
    size_t end_n;
public:
    explicit FibRange(size_t NewEnd_n):end_n{NewEnd_n}{}
    Fibit begin() const { return Fibit{};}
    Fibit end() const {return Fibit{end_n};}
};
#endif //CPP17_FIBONACCI_H
