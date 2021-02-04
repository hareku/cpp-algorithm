#ifndef LIB_MATH_EXTENDED_EUCLIDEAN_HPP
#define LIB_MATH_EXTENDED_EUCLIDEAN_HPP 1

#include <bits/stdc++.h>

namespace lib::math {

// return {x, y} of `ax + by = gcd(a, b)`
std::pair<long long, long long> extended_euclidean_algorithm(long long a, long long b) {
    auto f = [](auto self, long long a, long long b, long long &x, long long &y)->void {
        if(b == 0) {
            x = 1;
            y = 0;
            return;
        }

        self(self, b, a % b, y, x);
        y -= (a / b) * x;
    };

    long long x, y;
    f(f, a, b, x, y);

    return {x, y};
}

}  // namespace lib::math

#endif  // LIB_MATH_EXTENDED_EUCLIDEAN_HPP
