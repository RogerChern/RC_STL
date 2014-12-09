//
//  allocator.h
//  RC_STL
//
//  Created by RogerChen on 14/12/8.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef RC_STL_allocator_h
#define RC_STL_allocator_h

#include <cstddef>
#include <memory>
#include <limits>

namespace RC {
    
    template <typename T>
    class allocator {
    public://type member for STL interface
        using size_type       = std::size_t;
        using difference_type = std::ptrdiff_t;
        using pointer         = T *;
        using const_pointer   = const T *;
        using reference       = T &;
        using const_reference = const T &;
        using value_type      = T;
        
    public:
        allocator() noexcept = default;
        allocator(const allocator &) noexcept = default;
        allocator(allocator &&) noexcept = default;
        ~allocator() noexcept = default;
        allocator & operator=(const allocator &) noexcept = default;
        allocator & operator=(allocator &&) noexcept = default;
        
        template <typename U>
        allocator(const allocator<U> &) noexcept {}
        
        
        pointer allocate(size_type num) {
            return static_cast<pointer>(::operator new(num * sizeof(T)));
        }
        
        void deallocate(pointer p, size_type num) {
            ::operator delete(p);
        }
        
    };
    
    template <typename T1, typename T2>
    bool operator==(const allocator<T1> &, const allocator<T2> &) noexcept {
        return true;
    }
    
    template <typename T1, typename T2>
    bool operator!=(const allocator<T1> &, const allocator<T2> &) noexcept {
        return false;
    }
}

#endif
