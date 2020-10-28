#ifndef LIB_MATH_OVERFLOW_HPP
#define LIB_MATH_OVERFLOW_HPP 1

#include <bits/stdc++.h>

namespace lib::math {

template <class T> bool overflow_if_add(T a, T b) {
    return (std::numeric_limits<T>::max() - a) < b;
}

template <class T> bool overflow_if_mul(T a, T b) {
    return (std::numeric_limits<T>::max() / a) < b;
}

}  // namespace lib::math

#endif  // LIB_MATH_OVERFLOW_HPP
