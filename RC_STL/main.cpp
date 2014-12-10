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
#include <type_traits>
#include "allocator.h"
#include "vector.h"
#include "__vector_v1.h"

using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {
    //unit test for    passed
    //iterator insert(iterator pos, const_reference value);
    /*
    _v1::vector a(1, -100);
    for (int i = 0; i < 20; ++i) {
        auto beg = a.begin();
        a.insert(beg, i);
        cout << a.size() << ' ' << a.capacity() << endl;
    }
    for (auto &&i : a) {
        cout << i << ' ';
    }
    cout << endl;
    
    std::vector<int> b(1, -100);
    for (int i = 0; i < 20; ++i) {
        auto beg = b.begin();
        b.insert(beg, i);
        cout << b.size() << ' ' << b.capacity() << endl;
    }
    for (auto &&i : b) {
        cout << i << ' ';
    }
    cout << endl;
    */
    //unit test for    passed
    //void insert(iterator pos, size_type count, const_reference value);
    /*
    _v1::vector insert_2(1, -100);
    for (int i = 0; i < 5; ++i) {
        auto insert_2_beg = insert_2.begin();
        insert_2.insert(insert_2_beg, i, i);
        cout << insert_2.size() << ' ' << insert_2.capacity() << endl;
    }
    for (auto &&x : insert_2) {
        cout << x << ' ';
    }
    cout << endl;
    
    std::vector<int> insert_2s(1, -100);
    for (int i = 0; i < 5; ++i) {
        auto insert_2s_beg = insert_2s.begin();
        insert_2s.insert(insert_2s_beg, i, i);
        cout << insert_2s.size() << ' ' << insert_2s.capacity() << endl;
    }
    for (auto &&x : insert_2s) {
        cout << x << ' ';
    }
    cout << endl;
    */
    
    /*
    _v1::vector b;
    for (int i = 0; i < 10; ++i) {
        b.push_back(i);
        cout << b[i] << endl;
        cout << b.size() << endl;
        cout << b.capacity() << endl;
        cout << endl;
    }
    int arr[5] = {0};
    _v1::vector c(arr, arr+5);
    c[4] = 1;
    for (int i = 0; i < c.size(); ++i) {
        cout << c[i] << ' ';
    }
    cout << endl;
    
    _v1::vector d(b);
    for (int i = 0; i < 10; ++i) {
        cout << d[i] << endl;
    }
    
    d = c;
    for (int i = 0; i < d.size(); ++i) {
        cout << d[i] << endl;
    }
    
    d.assign(4, 1);
    for (int i = 0; i < d.size(); ++i) {
        cout << d[i] << endl;
    }
    
    d.assign(arr, arr+5);
    for (int i = 0; i < d.size(); ++i) {
        cout << d[i] << endl;
    }
    
    cout << b.front() << endl;
    cout << b.back() << endl;
    cout << b.capacity() << endl;
    b.reserve(100);
    cout << b.capacity() << endl;
    for (int i = 0; i < b.size(); ++i) {
        cout << b[i] << ' ';
    }
    cout << endl;
     */
    return 0;
}
