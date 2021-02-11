#ifndef LIB_MATH_COPRIME_HPP
#define LIB_MATH_COPRIME_HPP 1

#include <bits/stdc++.h>

namespace lib::math {

// Enumerate coprimes of `a` that are `n` or lower.
std::vector<long long> enumerate_coprimes(long long a, long long n) {
    std::vector<long long> res;

    long long start = (a % 2 == 0) ? 3 : 2;
    long long amount = (a % 2 == 0) ? 2 : 1;
    for(long long x = start; x <= n; x += amount) {
        if(std::__gcd(a, x) == 1) {
            res.push_back(x);
        }
    }

    return res;
}

}  // namespace lib::math

#endif  // LIB_MATH_COPRIME_HPP
