//
//  RcAlloc.h
//  RC_STL
//
//  Created by RogerChen on 14/12/8.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef RC_STL_RcAlloc_h
#define RC_STL_RcAlloc_h

#include <cstddef>
#include <memory.h>
#include <limits.h>

template <typename T>
class RcAlloc {
public://type member for STL interface
    using size_type       = std::size_t;
    using difference_type = std::ptrdiff_t;
    using pointer         = T *;
    using const_pointer   = const T *;
    using reference       = T &;
    using const_reference = const T &;
    using value_type      = T;

public:
    RcAlloc() noexcept = default;
    RcAlloc(const RcAlloc &) noexcept = default;
    RcAlloc(RcAlloc &&) noexcept = default;
    ~RcAlloc() noexcept = default;
    RcAlloc & operator=(const RcAlloc &) noexcept = default;
    RcAlloc & operator=(RcAlloc &&) noexcept = default;
    
    template <typename U>
        RcAlloc(const RcAlloc<U> &) noexcept {}
    
    
    pointer allocate(size_type num) {
        return static_cast<pointer>(::operator new(num * sizeof(T)));
    }
    
    void deallocate(pointer p, size_type num) {
        ::operator delete(p);
    }
    
};

template <typename T1, typename T2>
bool operator==(const RcAlloc<T1> &, const RcAlloc<T2> &) noexcept {
    return true;
}

template <typename T1, typename T2>
bool operator!=(const RcAlloc<T1> &, const RcAlloc<T2> &) noexcept {
    return false;
}
#endif
