#ifndef LIB_MATH_COMBINATION_HPP
#define LIB_MATH_COMBINATION_HPP 1

#include <bits/stdc++.h>

namespace lib::math {

long long ncr(long long n, long long r) {
    if(r == 0) return 1;
    if(r > n) return 0;

    long long res = 1;
    for(long long i = 0; i < r; i++) {
        res *= (n - i);
        res /= i + 1;
    }

    return res;
}

long long nhr(long long n, long long r) {
    return ncr(n + r - 1, r);
}

}  // namespace lib::math

#endif  // LIB_MATH_COMBINATION_HPP
