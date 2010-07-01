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


/*! \file logical.inl
 *  \brief Inline file for logical.h.
 */

#include <thrust/functional.h>
#include <thrust/iterator/transform_iterator.h>
#include <thrust/find.h>
#include <thrust/iterator/iterator_traits.h>

// TODO don't rely on (bool) pred(x) to convert non-boolean predicate results (produces MSVC warning C4800)

namespace thrust
{

template <class InputIterator, class Predicate>
bool all_of(InputIterator first, InputIterator last, Predicate pred)
{
    typedef typename thrust::transform_iterator<Predicate, InputIterator, bool> PredicateIterator;

    PredicateIterator p_first(first, pred);
    PredicateIterator p_last(last, pred);

    return thrust::find(p_first, p_last, false) == p_last;
}

template <class InputIterator, class Predicate>
bool any_of(InputIterator first, InputIterator last, Predicate pred)
{
    typedef typename thrust::transform_iterator<Predicate, InputIterator, bool> PredicateIterator;

    PredicateIterator p_first(first, pred);
    PredicateIterator p_last(last, pred);

    return thrust::find(p_first, p_last, true) != p_last;
}

template <class InputIterator, class Predicate>
bool none_of(InputIterator first, InputIterator last, Predicate pred)
{
    return !thrust::any_of(first, last, pred);
}

} // end namespace thrust

