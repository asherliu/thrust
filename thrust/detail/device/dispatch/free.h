/*
 *  Copyright 2008-2009 NVIDIA Corporation
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

#pragma once

#include <thrust/device_ptr.h>
#include <thrust/iterator/iterator_traits.h>
#include <thrust/detail/device/generic/free.h>
#include <thrust/detail/device/cuda/free.h>

namespace thrust
{

namespace detail
{

namespace device
{

namespace dispatch
{

inline void free(thrust::device_ptr<void> ptr,
                 thrust::device_space_tag)
{
  return thrust::detail::device::generic::free(ptr);
} // end free()

inline void free(thrust::device_ptr<void> ptr,
                 thrust::detail::cuda_device_space_tag)
{
  return thrust::detail::device::cuda::free(ptr);
} // end free()

} // end dispatch

} // end device

} // end detail

} // end thrust


