//
// Created by Manoloon on 29/9/2023.
//

#ifndef CPP17_BASICLAMBDA_H
#define CPP17_BASICLAMBDA_H
auto plus{[](auto a,auto b){return (a+b);}};
auto count{[count=0]() mutable {return ++count;}};

// this lambda need to be inside the main scope
//auto addTen([=](int x){return plus(10,x);});
//int a=0;
//auto countRef{[&a]{return ++a;}};

#endif //CPP17_BASICLAMBDA_H
