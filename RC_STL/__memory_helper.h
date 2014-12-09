//
//  __memory_helper.h
//  RC_STL
//
//  Created by RogerChen on 14/12/9.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef RC_STL___memory_helper_h
#define RC_STL___memory_helper_h

namespace RC {
    template <typename T>
    struct default_delete
    {
        constexpr default_delete() noexcept = default;
        template <class U>
            default_delete(const default_delete<U>&) noexcept;
        
        void operator()(T*) const noexcept;
    };
    
    template <typename T>
    struct default_delete<T[]>
    {
        constexpr default_delete() noexcept = default;
        void operator()(T*) const noexcept;
        template <class U>
            void operator()(U*) const = delete;
    };
}
#endif
