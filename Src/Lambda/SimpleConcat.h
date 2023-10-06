//
// Created by Manoloon on 6/10/2023.
//

#ifndef CPP17_SIMPLECONCAT_H
#define CPP17_SIMPLECONCAT_H

template<typename F,typename G,typename H>
auto SimpleConcat(F f,G g, H h)
{
    return [=](auto ...params)
    {
        return f(g(h(params...)));
    };
}
auto const SimpleTwice ([](int i){return i * 2;});
auto const SimpleThrice ([](int i){return i * 3;});
auto const SimpleCombined(SimpleConcat(SimpleTwice,SimpleThrice,std::plus<int>{}));
#endif //CPP17_SIMPLECONCAT_H
