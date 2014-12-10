//
//  __vector_v1.h
//  RC_STL
//
//  Created by RogerChen on 14/12/10.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef RC_STL___vector_v1_h
#define RC_STL___vector_v1_h


namespace _v1 {
    //template<typename int>
    class vector {
    public:
        using value_type = int;
        using iterator = int *;
        using const_iterator = const int *;
        using size_type = size_t;
        using reference = int &;
        using const_reference = const int &;
    private:
        iterator _begin = nullptr;
        iterator _end = nullptr;
        iterator _end_cap = nullptr;
    private:
        void reallocate() {
            size_type size = _end - _begin;
            size_type cap = _end_cap - _begin;
            size_type new_cap = (cap == 0) ? 1 : cap * 2;
            iterator temp = new value_type[new_cap];
            for (int i = 0; i < size; ++i) {
                temp[i] = _begin[i];
            }
            delete [] _begin;
            _begin = temp;
            _end = _begin + size;
            _end_cap = _begin + new_cap;
        }
    public:
        //special member funcions
        vector() noexcept = default;
        vector(size_type count, const_reference value) {
            size_t size = 1;
            while (size < count) {
                size *= 2;
            }
            _begin   = new value_type[size];
            _end     = _begin + count;
            _end_cap = _begin + size;
            for(int i = 0; i < count; ++i) {
                _begin[i] = value;
            }
        }
        vector(iterator first, iterator last) {
            size_t length = last - first;
            if (length > 0) {
                size_t size = 1;
                while (size <= length) {
                    size *= 2;
                }
                _begin = new value_type[size];
                _end = _begin + length;
                _end_cap = _begin + size;
                for (int i = 0; first != last; ++i) {
                    _begin[i] = *first++;
                }
            }
        }
        vector(const vector &other) {
            _begin = new value_type[other.capacity()];
            _end   = _begin + other.size();
            _end_cap = _begin + other.capacity();
            for (int i = 0; i < other.size(); ++i) {
                _begin[i] = other[i];
            }
        }
        ~vector() {
            delete [] _begin;
        }
        vector & operator=(const vector &other) {
            iterator backup = _begin;
            _begin = new value_type[other.capacity()];
            _end = _begin + other.size();
            _end_cap = _begin + other.capacity();
            for (int i = 0; i < _end - _begin; ++i) {
                _begin[i] = other[i];
            }
            delete [] backup;
            return *this;
        }
        void assign(size_type count, const_reference value) {
            vector temp(count, value);
            *this = temp;
        }
        void assign(iterator first, iterator last) {
            vector temp(first, last);
            *this = temp;
        }
        
        //accessors
        reference at(size_type pos) {
            if (pos >= size()) {
                throw std::out_of_range("vector.at: out of range exception!");
            }
            else {
                return _begin[pos];
            }
        }
        const_reference at(size_type pos) const {
            if (pos >= size()) {
                throw std::out_of_range("vector.at: out of range exception!");
            }
            else {
                return _begin[pos];
            }
        }
        reference operator[](size_type n) {
            return *(_begin + n);
        }
        const_reference operator[](size_type n) const {
            return *(_begin + n);
            
        }
        reference front() {
            return _begin[0];
        }
        const_reference front() const {
            return *_begin;
        }
        reference back() {
            return *(_end - 1);
        }
        const_reference back() const {
            return *(_end -1);
        }
        
        //iterator
        iterator begin() {
            return _begin;
        }
        const_iterator begin() const {
            return _begin;
        }
        iterator end() {
            return _end;
        }
        const_iterator end() const {
            return _end;
        }
        
        //capacity
        bool empty() const {
            return _end == _begin;
        }
        size_type size() const {
            return _end - _begin;
        }
        size_type maxsize() const = delete;//no going to implement it
        void reserve(size_type new_cap) {
            if (new_cap > _end_cap - _begin) {
                iterator temp = new value_type[new_cap];
                for (int i = 0; i < _end - _begin; ++i) {
                    temp[i] = _begin[i];
                }
                _end = temp + (_end - _begin);
                delete [] _begin;
                _begin = temp;
                _end_cap = _begin + new_cap;
            }
        }
        size_type capacity() const {
            return _end_cap - _begin;
        }
        
        //modifiers
        void clear() {
            _end = _begin;
        }
        iterator insert(iterator pos, const_reference value) {
            if (_end == _end_cap) {
                auto offset = pos - _begin;
                reallocate();
                pos = _begin + offset;
            }
            ++_end;
            for (auto it = _end - 1; it != pos; --it) {
                *it = *(it - 1);
            }
            *pos = value;

            return pos;
        }
        void insert(iterator pos, size_type count, const_reference value) {
            while (_end + count - 1 >= _end_cap) {
                auto offset = pos - _begin;
                reallocate();
                pos = _begin + offset;
            }
            _end += count;
            for (auto it = _end - 1; it != pos + count - 1; --it) {
                *it = *(it - count);
            }
            for (int i = 0; i < count; ++i) {
                *pos++ = value;
            }
        }
        void insert(iterator pos, iterator first, iterator last);
        void push_back(const_reference item) {
            if (_end != _end_cap) {
                *_end++ = item;
            }
            else {
                reallocate();
                push_back(item);
            }
        }
        void pop_back() {
            --_end;
        }
    };
}
#endif
