/*
 *  Copyright 2008-2011 NVIDIA Corporation
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

#include <thrust/detail/config.h>
#include <thrust/detail/backend/omp/copy.h>
#include <thrust/detail/backend/generic/copy.h>
#include <thrust/detail/type_traits/minimum_type.h>

namespace thrust
{
namespace detail
{
namespace backend
{
namespace omp
{
namespace detail
{


template<typename InputIterator,
         typename OutputIterator>
  OutputIterator copy(InputIterator first,
                      InputIterator last,
                      OutputIterator result,
                      thrust::incrementable_traversal_tag)
{
  return thrust::detail::backend::cpp::copy(tag(), first, last, result);
} // end copy()


template<typename InputIterator,
         typename OutputIterator>
  OutputIterator copy(InputIterator first,
                      InputIterator last,
                      OutputIterator result,
                      thrust::random_access_traversal_tag)
{
  return thrust::detail::backend::generic::copy(tag(), first, last, result);
} // end copy()


template<typename InputIterator,
         typename Size,
         typename OutputIterator>
  OutputIterator copy_n(InputIterator first,
                        Size n,
                        OutputIterator result,
                        thrust::incrementable_traversal_tag)
{
  return thrust::detail::backend::cpp::copy_n(tag(), first, n, result);
} // end copy_n()


template<typename InputIterator,
         typename Size,
         typename OutputIterator>
  OutputIterator copy_n(InputIterator first,
                        Size n,
                        OutputIterator result,
                        thrust::random_access_traversal_tag)
{
  return thrust::detail::backend::generic::copy_n(tag(), first, n, result);
} // end copy_n()


} // end detail


template<typename InputIterator,
         typename OutputIterator,
         typename Tag>
OutputIterator copy(Tag,
                    InputIterator first,
                    InputIterator last,
                    OutputIterator result)
{
  typedef typename thrust::iterator_traversal<InputIterator>::type  traversal1;
  typedef typename thrust::iterator_traversal<OutputIterator>::type traversal2;
  
  typedef typename thrust::detail::minimum_type<traversal1,traversal2>::type traversal;

  // dispatch on minimum traversal
  return thrust::detail::backend::omp::detail::copy(first,last,result,traversal());
} // end copy()



template<typename InputIterator,
         typename Size,
         typename OutputIterator,
         typename Tag>
OutputIterator copy_n(Tag,
                      InputIterator first,
                      Size n,
                      OutputIterator result)
{
  typedef typename thrust::iterator_traversal<InputIterator>::type  traversal1;
  typedef typename thrust::iterator_traversal<OutputIterator>::type traversal2;
  
  typedef typename thrust::detail::minimum_type<traversal1,traversal2>::type traversal;

  // dispatch on minimum traversal
  return thrust::detail::backend::omp::detail::copy_n(first,n,result,traversal());
} // end copy_n()


} // end namespace omp
} // end namespace backend
} // end namespace detail
} // end namespace thrust

