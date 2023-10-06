#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Src/Lambda/Concatenation.h"
#include "Src/Lambda/SimpleConcat.h"
#include "Src/Lambda/consumer.h"

int main()
{
    Consumer::FeedConsumers(10);

    std::cout << combined(2,3) << std::endl;
    std::cout << SimpleCombined(2,3) << std::endl;
        return 0;
}
