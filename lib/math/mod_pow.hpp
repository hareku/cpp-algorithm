#ifndef LIB_MATH_MOD_POW_HPP
#define LIB_MATH_MOD_POW_HPP 1

#include <bits/stdc++.h>

namespace lib::math {

// a^n mod(m)
// O(log{2} n)
long long mod_pow(long long a, long long n, long long m) {
    a %= m;
    long long res = 1;
    while (n != 0) {
        if (n & 1) res = res * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

// a^n mod(m)
// O(log{2} n)
__uint128_t mod_pow_int128(__uint128_t a, __uint128_t n, __uint128_t m) {
    assert(0 <= n);
    assert(1 <= m);
    __uint128_t res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

}  // namespace lib::math

#endif  // LIB_MATH_MOD_POW_HPP
