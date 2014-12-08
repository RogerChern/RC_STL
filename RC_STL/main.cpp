//
//  main.cpp
//  RC_STL
//
//  Created by RogerChen on 14/12/8.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <ctime>
#include "RcAlloc.h"

int main(int argc, const char * argv[]) {
    
    std::vector<int, RcAlloc<int>> RcVec;
    std::vector<int, RcAlloc<int>> vec;
    
    auto start = clock();
    for (int i = 0; i < 10000; ++i)
        RcVec.push_back(i);
    auto middle = clock();
    for (int i = 0; i < 10000; ++i)
        vec.emplace_back(i);
    auto end = clock();
    
    RcVec = vec;
    
    std::cout << "RcAlloc consumes " << double(middle - start) / CLOCKS_PER_SEC  * 1000 << "ms\n";
    std::cout << "Default alloc consumes " << double(end - middle) / CLOCKS_PER_SEC  * 1000 << "ms\n";
    return 0;
}
