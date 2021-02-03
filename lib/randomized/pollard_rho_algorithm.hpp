#ifndef LIB_RANDOMIZED_POLLARD_RHO_ALGORITHM_HPP
#define LIB_RANDOMIZED_POLLARD_RHO_ALGORITHM_HPP 1

#include <bits/stdc++.h>
#include "./miller_rabin_primality_test.hpp"

namespace lib::randomized {

__uint128_t pollard_rho_algorithm(__uint128_t n) {
    if(lib::randomized::miller_rabin_primality_test(n)) {
        return n;
    }
    if(n % 2 == 0) {
        return 2;
    }

    __uint128_t g;
    int c = 1;
    auto f = [&n, &c](__uint128_t x) {
        return (x * x + c) % n;
    };

    while(true) {
        __uint128_t x = 2, y = 2;
        do {
            x = f(x);
            y = f(f(y));
            g = std::__gcd<__uint128_t>(n, std::max(x, y) - std::min(x, y));
        } while(g == 1);
        if(g < n) {
            return g;
        }
        ++c;
    }

    assert(0);
}

std::vector<std::pair<long long, int>> pollard_rho_prime_factorization(long long n) {
    std::vector<std::pair<long long, int>> res;
    if(n == 1) {
        return res;
    }

    std::vector<long long> primes;
    auto factor = [&primes](auto self, long long a)->void {
        if(a == 1) return;

        long long m = pollard_rho_algorithm(a);
        if(m == a) {
            primes.push_back(a);
            return;
        }

        self(self, m);
        self(self, a / m);
    };

    factor(factor, n);

    std::sort(primes.begin(), primes.end());
    for(auto p : primes) {
        if(!res.empty() && res.back().first == p) {
            res.back().second++;
        } else {
            res.push_back({p, 1});
        }
    }

    return res;
}

}  // namespace lib::randomized

#endif  // LIB_RANDOMIZED_POLLARD_RHO_ALGORITHM_HPP
