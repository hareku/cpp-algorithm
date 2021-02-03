#ifndef LIB_RANDOMIZED_MILLER_RABIN_PRIMALITY_TEST_HPP
#define LIB_RANDOMIZED_MILLER_RABIN_PRIMALITY_TEST_HPP 1

#include <bits/stdc++.h>
#include "../math/mod_pow.hpp"

namespace lib::randomized {

// O(k log{3} n)
bool miller_rabin_primality_test(long long n, int k = 20) {
    // n must be greater than 3.
    if(n == 2 || n == 3) {
        return true;
    }
    // 1 or even numbers that are grater than 2 are not prime numbers.
    if(n <= 1 || !(n & 1)) {
        return false;
    }

    long long d = n - 1;
    int s = 0;
    while(!(d & 1)) {
        d >>= 1;
        ++s;
    }

    std::random_device seed_gen;
    std::mt19937_64 engine(seed_gen());
    std::uniform_int_distribution<long long> rand(1, n - 1);

    for(int ki = 0; ki < k; ++ki) {
        long long a = rand(engine);
        long long x = lib::math::mod_pow_int128(a, d, n);

        if(x == 1 || x == n - 1) {
            continue;
        }

        bool ok = 0;
        for (int r = 1; r <= s - 1; ++r) {
            x = lib::math::mod_pow_int128(x, 2, n);
            if(x == 1) {
                return false;
            }
            if(x == n - 1) {
                ok = 1;
                break;
            }
        }

        if(ok) continue;

        return false;
    }

    return true;
}

}  // namespace lib::randomized

#endif  // LIB_RANDOMIZED_MILLER_RABIN_PRIMALITY_TEST_HPP
