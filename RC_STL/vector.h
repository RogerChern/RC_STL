//
//  vector.h
//  RC_STL
//
//  Created by RogerChen on 14/12/10.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef RC_STL_vector_h
#define RC_STL_vector_h
#include <type_traits>

namespace RC {
    template <typename T, typename Allocator = allocator<T> >
    class vector
    {
    public:
        using value_type             = T;
        using allocator_type         = Allocator;
        using reference              = typename allocator_type::reference;
        using const_reference        = typename allocator_type::const_reference;
        using iterator               = typename allocator_type::pointer;
        using const_iterator         = typename allocator_type::pointer;
        using size_type              = typename allocator_type::size_type;
        using difference_type        = typename allocator_type::difference_type;
        using pointer                = typename allocator_type::pointer;
        using const_pointer          = typename allocator_type::const_pointer;
        using reverse_iterator       = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;
    private:
        pointer _start   = nullptr;
        pointer _end     = nullptr;
        std::pair<allocator_type, pointer> _end_cap;
    private:
        allocator_type & alloc() noexcept {
            return _end_cap.first();
        }
    public:
        vector() noexcept(std::is_nothrow_default_constructible<allocator_type>::value);
        ~vector() {
            alloc().deallocate(_start, _end - _start);
        }
        
        explicit vector(const allocator_type&);
        explicit vector(size_type n) {
            _start = allocator_type(n);
            
        }
        explicit vector(size_type n, const allocator_type&); // C++14
        vector(size_type n, const value_type& value, const allocator_type& = allocator_type());
        template <class InputIterator>
            vector(InputIterator first, InputIterator last, const allocator_type& = allocator_type());
        vector(const vector& x);
        vector(vector&& x)
        noexcept(std::is_nothrow_move_constructible<allocator_type>::value);
        vector(std::initializer_list<value_type> il);
        vector(std::initializer_list<value_type> il, const allocator_type& a);
        vector& operator=(const vector& x);
        vector& operator=(vector&& x)
        noexcept(
                 allocator_type::propagate_on_container_move_assignment::value &&
                 std::is_nothrow_move_assignable<allocator_type>::value);
        vector& operator=(std::initializer_list<value_type> il);
        template <class InputIterator>
            void assign(InputIterator first, InputIterator last);
        void assign(size_type n, const value_type& u);
        void assign(std::initializer_list<value_type> il);
        
        allocator_type get_allocator()   const noexcept;
        
        iterator               begin()   noexcept;
        const_iterator         begin()   const noexcept;
        iterator               end()     noexcept;
        const_iterator         end()     const noexcept;
        
        reverse_iterator       rbegin()  noexcept;
        const_reverse_iterator rbegin()  const noexcept;
        reverse_iterator       rend()    noexcept;
        const_reverse_iterator rend()    const noexcept;
        
        const_iterator         cbegin()  const noexcept;
        const_iterator         cend()    const noexcept;
        const_reverse_iterator crbegin() const noexcept;
        const_reverse_iterator crend()   const noexcept;
        
        size_type size()     const noexcept;
        size_type max_size() const noexcept;
        size_type capacity() const noexcept;
        bool empty()         const noexcept;
        void reserve(size_type n);
        void shrink_to_fit() noexcept;
        
        reference       operator[](size_type n);
        const_reference operator[](size_type n) const;
        reference       at(size_type n);
        const_reference at(size_type n) const;
        
        reference       front();
        const_reference front() const;
        reference       back();
        const_reference back() const;
        
        value_type*       data() noexcept;
        const value_type* data() const noexcept;
        
        void push_back(const value_type& x);
        void push_back(value_type&& x);
        template <class... Args>
            void emplace_back(Args&&... args);
        void pop_back();
        
        template <class... Args>
            iterator emplace(const_iterator position, Args&&... args);
        iterator insert(const_iterator position, const value_type& x);
        iterator insert(const_iterator position, value_type&& x);
        iterator insert(const_iterator position, size_type n, const value_type& x);
        template <class InputIterator>
            iterator insert(const_iterator position, InputIterator first, InputIterator last);
        iterator insert(const_iterator position, std::initializer_list<value_type> il);
        
        iterator erase(const_iterator position);
        iterator erase(const_iterator first, const_iterator last);
        
        void clear() noexcept;
        
        void resize(size_type sz);
        void resize(size_type sz, const value_type& c);
        
        void swap(vector&)
        noexcept(!allocator_type::propagate_on_container_swap::value ||
                 std::__is_nothrow_swappable<allocator_type>::value);
        
        bool __invariants() const;
    };
    
    template <class T, class Allocator>
        bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    template <class T, class Allocator>
        bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    template <class T, class Allocator>
        bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    template <class T, class Allocator>
        bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    template <class T, class Allocator>
        bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    template <class T, class Allocator>
        bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
    
    template <class T, class Allocator>
        void swap(vector<T,Allocator>& x, vector<T,Allocator>& y) noexcept(noexcept(x.swap(y)));
} //end of namespace RC

#endif
