#ifndef LIB_MATH_PRIME_FACTORIZATION_HPP
#define LIB_MATH_PRIME_FACTORIZATION_HPP 1

#include <bits/stdc++.h>

namespace lib::math {

std::vector<std::pair<long long, int>> prime_factorization(long long x) {
    std::vector<std::pair<long long, int>> res;

    for (long long a = 2; a * a <= x; ++a) {
        if (x % a != 0) continue;

        int ex = 0;
        while (x % a == 0) {
            ++ex;
            x /= a;
        }

        res.push_back({a, ex});
    }

    if (x != 1) {
        res.push_back({x, 1});
    }
    return res;
}

}  // namespace lib::math

#endif  // LIB_MATH_PRIME_FACTORIZATION_HPP
