/*
 *  Copyright 2008-2010 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/*! \file ogl_interop_allocator.h
 *  \brief A memory allocator for OpenGL buffer objects.
 */

#pragma once

#include <thrust/detail/config.h>
#include <thrust/device_ptr.h>
#include <thrust/device_reference.h>
#include <cuda_gl_interop.h>
#include <map>
#include <limits>
#include <stdexcept>

template<typename T>
  class ogl_interop_allocator
{
  public:
    typedef T                                 value_type;
    typedef thrust::device_ptr<T>             pointer;
    typedef thrust::device_ptr<const T>       const_pointer;
    typedef thrust::device_reference<T>       reference;
    typedef thrust::device_reference<const T> const_reference;
    typedef std::size_t                       size_type;
    typedef typename pointer::difference_type difference_type;

    template<typename U>
      struct rebind
    {
      typedef ogl_interop_allocator<U> other;
    }; // end rebind

    inline ogl_interop_allocator(void);

    inline ogl_interop_allocator(const ogl_interop_allocator &a);

    template<typename U>
    inline ogl_interop_allocator(const ogl_interop_allocator<U> &a);

    // address
    inline pointer address(reference r);
    
    inline const_pointer address(const_reference r);

    // memory allocation
    inline pointer allocate(size_type cnt,
                            const_pointer = const_pointer(static_cast<T*>(0)));

    inline void deallocate(pointer p, size_type cnt);

    inline size_type max_size(void) const;

    inline bool operator==(const ogl_interop_allocator &rhs);

    inline bool operator!=(const ogl_interop_allocator &rhs);

    static inline GLuint get_buffer_object(pointer ptr);

  private:
    static std::map<pointer, GLuint> s_pointer_to_buffer_object;
};

#include <thrust/experimental/cuda/detail/ogl_interop_allocator.inl>

