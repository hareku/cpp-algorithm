#ifndef LIB_MATH_PRIME_FACTORIZER_HPP
#define LIB_MATH_PRIME_FACTORIZER_HPP 1

#include <bits/stdc++.h>

namespace lib::math {

struct prime_factorizer {
  public:
    // O(sqrt(N))
    prime_factorizer(long long n) : _n(n) {
        init();
    }

    // O(logX)
    std::vector<std::pair<long long, int>> factorize(long long x) {
        assert(1 <= x && x <= _n);

        std::vector<std::pair<long long, int>> res;

        for(long long p : primes) {
            if(p > x) break;
            if (x % p != 0) continue;

            int ex = 0;
            while (x % p == 0) {
                ++ex;
                x /= p;
            }

            res.push_back({p, ex});
        }

        if (x != 1) {
            res.push_back({x, 1});
        }
        return res;
    }

  private:
    void init() {
        is_p.resize(_n + 1, true);
        is_p[0] = is_p[1] = false;

        for (long long a = 2; a * a <= _n; ++a) {
            if(!is_p[a]) continue;

            primes.insert(a);
            for(long long m = a * 2; m <= _n; m += a) {
                is_p[m] = false;
            }
        }
    }

    long long _n;
    std::set<long long> primes;
    std::vector<bool> is_p;
};

}  // namespace lib::math

#endif  // LIB_MATH_PRIME_FACTORIZER_HPP
