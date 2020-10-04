#ifndef LIB_MATH_LCM_HPP
#define LIB_MATH_LCM_HPP 1

#include <bits/stdc++.h>

namespace lib::math {

template <class T> T lcm(T a, T b) {
    return a * b / std::__gcd(a, b);
}

}  // namespace lib::math

#endif  // LIB_MATH_LCM_HPP
