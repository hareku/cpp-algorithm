#include <bits/stdc++.h>

namespace mylib {

// Enumerate divisors of "x"
// O(sqrt(N))
std::vector<long long> divisors(long long x) {
    std::vector<long long> res;
    for (long long i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            res.push_back(i);
            if (x / i != i) {
                res.push_back(x / i);
            }
        }
    }

    std::sort(res.begin(), res.end());
    return res;
}

}  // namespace mylib
