//
// Created by Manoloon on 27/11/2023.
//
#ifndef CPP17_SORTING_H
#define CPP17_SORTING_H
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>

struct Point2D{
    int x;
    int y;
};
static void print(const std::vector<int> &v){
    std::copy(std::begin(v),std::end(v),std::ostream_iterator<int>{std::cout, ", "});
    std::cout << "\n";
}
void CreateAndSortVector(std::vector<int> v){
    std::random_device rd;
    std::mt19937 RGen{rd()};
    print(v);
    std::cout << "Is Sorted? " << std::is_sorted(std::begin(v),std::end(v)) << "\n";
    std::shuffle(std::begin(v),std::end(v),RGen);
    std::cout << "Shuffled " << "\n";
    std::cout << "Is Sorted? " << std::is_sorted(std::begin(v),std::end(v)) << "\n";
    std::sort(std::begin(v),std::end(v));
    std::cout << "Sorted " << "\n";
    std::cout << "Is Sorted? " << std::is_sorted(std::begin(v),std::end(v)) << "\n";
    print(v);
    // partition
    std::shuffle(std::begin(v),std::end(v),RGen);
    std::partition(std::begin(v),std::end(v),[](int i){return i < 5;});
    std::cout << "Partition will move to the front the numbers < 5, they are not sorted" << "\n";
    print(v);
    //partial sort
    std::shuffle(std::begin(v),std::end(v),RGen);
    auto middle (std::next(std::begin(v),int(v.size()/2)));
    std::partial_sort(std::begin(v),middle,std::end(v));
    std::cout << "Partial Sorted from the middle" << "\n";
    print(v);

    // sorting data without comparison operator
    std::vector<Point2D> points{{5,100},{1,50},{-123,1000},{3,70},{-10,20}};
    std::sort(std::begin(points),std::end(points),
              [](const Point2D &p1, const Point2D &p2){
                  return p1.x < p2.x; });
    std::cout << "Sorted without a comparison operator" << "\n";
    for(const auto &[x,y]:points){
        std::cout << "{" << x << ", " << y << "}" ;
    }
    std::cout << std::endl;

}
#endif //CPP17_SORTING_H
