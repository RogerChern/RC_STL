//
//  __unique_ptr.h
//  RC_STL
//
//  Created by RogerChen on 14/12/9.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef RC_STL___unique_ptr_h
#define RC_STL___unique_ptr_h

#include <cstddef>
#include "__memory_helper.h"

namespace RC {
    template <typename T, typename D = default_delete<T>>
    class unique_ptr
    {
    public:
        using pointer = pointer_type_t<T, D>;
        using element_type = T;
        using deleter_type = D;
        
        // constructors
        constexpr unique_ptr() noexcept;
        explicit unique_ptr(pointer p) noexcept;
        unique_ptr(pointer p, const deleter_type  &d1) noexcept;
        unique_ptr(pointer p, deleter_type &&d2) noexcept;
        unique_ptr(unique_ptr &&u) noexcept;
        unique_ptr(nullptr_t) noexcept : unique_ptr() { }
        template <typename U, typename E>
            unique_ptr(unique_ptr<U, E> &&u) noexcept;
        //not going to implement auto_ptr, so this interface is muted
        //template <typename U>
        //    unique_ptr(auto_ptr<U> &&u) noexcept;
        
        // destructor
        ~unique_ptr();
        
        // assignment
        unique_ptr & operator=(unique_ptr &&u) noexcept;
        template <typename U, typename E>
            unique_ptr & operator=(unique_ptr<U, E> &&u) noexcept;
        unique_ptr & operator=(nullptr_t) noexcept;
        
        // observers
        element_type & operator*() const;
        pointer operator->() const noexcept;
        pointer get() const noexcept;
        deleter_type & get_deleter() noexcept;
        const deleter_type & get_deleter() const noexcept;
        explicit operator bool() const noexcept;
        
        // modifiers
        pointer release() noexcept;
        void reset(pointer p = pointer()) noexcept;
        void swap(unique_ptr &u) noexcept;
    };
    
    template <typename T, typename D>
    class unique_ptr<T[], D>
    {
    public:
        using pointer = pointer_type_t<T, D>;
        using element_type = T;
        using deleter_type = D;
        
        // constructors
        constexpr unique_ptr() noexcept;
        explicit unique_ptr(pointer p) noexcept;
        unique_ptr(pointer p, const deleter_type &d) noexcept;
        unique_ptr(pointer p, deleter_type &&d) noexcept;
        unique_ptr(unique_ptr &&u) noexcept;
        unique_ptr(nullptr_t) noexcept : unique_ptr() { }
        
        // destructor
        ~unique_ptr();
        
        // assignment
        unique_ptr & operator=(unique_ptr &&u) noexcept;
        unique_ptr & operator=(nullptr_t) noexcept;
        
        // observers
        element_type & operator[](size_t i) const;
        pointer get() const noexcept;
        deleter_type & get_deleter() noexcept;
        const deleter_type & get_deleter() const noexcept;
        explicit operator bool() const noexcept;
        
        // modifiers
        pointer release() noexcept;
        void reset(pointer p = pointer()) noexcept;
        void reset(nullptr_t) noexcept;
        template <typename U>
            void reset(U) = delete;
        void swap(unique_ptr &u) noexcept;
    };
    
    template <typename T, typename D>
        void swap(unique_ptr<T, D> &x, unique_ptr<T, D> &y) noexcept;
    
    template <typename T1, typename D1, typename T2, typename D2>
        bool operator==(const unique_ptr<T1, D1> &x, const unique_ptr<T2, D2> &y);
    template <typename T1, typename D1, typename T2, typename D2>
        bool operator!=(const unique_ptr<T1, D1> &x, const unique_ptr<T2, D2> &y);
    template <typename T1, typename D1, typename T2, typename D2>
        bool operator<(const unique_ptr<T1, D1> &x, const unique_ptr<T2, D2> &y);
    template <typename T1, typename D1, typename T2, typename D2>
        bool operator<=(const unique_ptr<T1, D1> &x, const unique_ptr<T2, D2> &y);
    template <typename T1, typename D1, typename T2, typename D2>
        bool operator>(const unique_ptr<T1, D1> &x, const unique_ptr<T2, D2> &y);
    template <typename T1, typename D1, typename T2, typename D2>
        bool operator>=(const unique_ptr<T1, D1> &x, const unique_ptr<T2, D2> &y);
    
    template <typename T, typename D>
        bool operator==(const unique_ptr<T, D> &x, nullptr_t) noexcept;
    template <typename T, typename D>
        bool operator==(nullptr_t, const unique_ptr<T, D> &y) noexcept;
    template <typename T, typename D>
        bool operator!=(const unique_ptr<T, D> &x, nullptr_t) noexcept;
    template <typename T, typename D>
        bool operator!=(nullptr_t, const unique_ptr<T, D> &y) noexcept;
    
    template <typename T, typename D>
        bool operator<(const unique_ptr<T, D> &x, nullptr_t);
    template <typename T, typename D>
        bool operator<(nullptr_t, const unique_ptr<T, D> &y);
    template <typename T, typename D>
        bool operator<=(const unique_ptr<T, D> &x, nullptr_t);
    template <typename T, typename D>
        bool operator<=(nullptr_t, const unique_ptr<T, D> &y);
    template <typename T, typename D>
        bool operator>(const unique_ptr<T, D> &x, nullptr_t);
    template <typename T, typename D>
        bool operator>(nullptr_t, const unique_ptr<T, D> &y);
    template <typename T, typename D>
        bool operator>=(const unique_ptr<T, D> &x, nullptr_t);
    template <typename T, typename D>
        bool operator>=(nullptr_t, const unique_ptr<T, D> &y);

}

#endif
