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


/*! \file merge_sort.inl
 *  \brief Inline file for merge_sort.h.
 */

#include <thrust/sort.h>

// forward everything to thrust/sort.h

// TODO issue deprecation warning

namespace thrust
{
namespace sorting
{

/////////
// Key //
/////////

template<typename RandomAccessIterator>
  void merge_sort(RandomAccessIterator first,
                  RandomAccessIterator last)
{
    thrust::sort(first, last);
}

template<typename RandomAccessIterator,
         typename StrictWeakOrdering>
  void merge_sort(RandomAccessIterator first,
                  RandomAccessIterator last,
                  StrictWeakOrdering comp)
{
    thrust::sort(first, last, comp);
}

template<typename RandomAccessIterator>
  void stable_merge_sort(RandomAccessIterator first,
                         RandomAccessIterator last)
{
    thrust::stable_sort(first, last);
}

template<typename RandomAccessIterator,
         typename StrictWeakOrdering>
  void stable_merge_sort(RandomAccessIterator first,
                         RandomAccessIterator last,
                         StrictWeakOrdering comp)
{
    thrust::stable_sort(first, last, comp);
}


///////////////
// Key Value //
///////////////

template<typename RandomAccessIterator1,
         typename RandomAccessIterator2>
  void merge_sort_by_key(RandomAccessIterator1 keys_first,
                         RandomAccessIterator1 keys_last,
                         RandomAccessIterator2 values_first)
{
    thrust::sort_by_key(keys_first, keys_last, values_first);
}

template<typename RandomAccessIterator1,
         typename RandomAccessIterator2,
         typename StrictWeakOrdering>
  void merge_sort_by_key(RandomAccessIterator1 keys_first,
                         RandomAccessIterator1 keys_last,
                         RandomAccessIterator2 values_first,
                         StrictWeakOrdering comp)
{
    thrust::sort_by_key(keys_first, keys_last, values_first, comp);
}


template<typename RandomAccessIterator1,
         typename RandomAccessIterator2>
  void stable_merge_sort_by_key(RandomAccessIterator1 keys_first,
                                RandomAccessIterator1 keys_last,
                                RandomAccessIterator2 values_first)
{
    thrust::stable_sort_by_key(keys_first, keys_last, values_first);
} 

template<typename RandomAccessIterator1,
         typename RandomAccessIterator2,
         typename StrictWeakOrdering>
  void stable_merge_sort_by_key(RandomAccessIterator1 keys_first,
                                RandomAccessIterator1 keys_last,
                                RandomAccessIterator2 values_first,
                                StrictWeakOrdering comp)
{
    thrust::stable_sort_by_key(keys_first, keys_last, values_first, comp);
}

} // end namespace sorting
} // end namespace thrust

