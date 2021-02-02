#ifndef LIB_MATH_PRIMES_HPP
#define LIB_MATH_PRIMES_HPP 1

#include <bits/stdc++.h>

namespace lib::math {

std::vector<long long> enumerate_primes(long long n) {
    std::vector<long long> primes;
    std::vector<bool> is_p(n + 1, true);

    for (long long a = 2; a <= n; ++a) {
        if(!is_p[a]) continue;

        primes.push_back(a);
        for(long long m = a * 2; m <= n; m += a) {
            is_p[m] = false;
        }
    }

    return primes;
}

}  // namespace lib::math

#endif  // LIB_MATH_PRIMES_HPP
