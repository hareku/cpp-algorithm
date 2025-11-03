#ifndef LIB_MATH_MOD_COMBINATOR_HPP
#define LIB_MATH_MOD_COMBINATOR_HPP 1

#include <bits/stdc++.h>

namespace lib::math {

struct mod_combinator {
  public:
    // O(N)
    mod_combinator(int n, long long mod) : _n(n), _mod(mod), fac(n + 1), ifac(n + 1) {
        assert(n < mod);

        fac[0] = 1;
        for (long long i = 1; i <= n; ++i) {
            fac[i] = fac[i - 1] * i % mod;
        }

        ifac[n] = inv(fac[n]);
        for (long long i = n; i >= 1; --i) {
            // (i-1)! = (i!)/i
            // -> {(i-1)!}^-1 = (i!)^-1 * i
            ifac[i - 1] = ifac[i] * i % mod;
        }
    }

    // O(1)
    long long ncr(long long n, long long r) {
        assert(n <= _n);
        assert(r <= _n);

        if (r < 0 || r > n) return 0;
        return fac[n] * (ifac[r] * ifac[n - r] % _mod) % _mod;
    }

    // O(1)
    long long nhr(long long n, long long r) {
        assert(n + r - 1 <= _n);
        assert(r <= _n);

        return ncr(n + r - 1, r);
    }

    // O(1)
    long long npr(long long n, long long r) {
        assert(n <= _n);
        assert(r <= _n);

        return fac[n] * ifac[n-r] % _mod;
    }

  private:
    int _n;
    long long _mod;
    std::vector<long long> fac, ifac;

    long long inv(long long a) {
        long long b = _mod, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; std::swap(a, b);
            u -= t * v; std::swap(u, v);
        }
        u %= _mod;
        if (u < 0) u += _mod;
        return u;
    }
};

}  // namespace lib::math

#endif  // LIB_MATH_MOD_COMBINATOR_HPP
