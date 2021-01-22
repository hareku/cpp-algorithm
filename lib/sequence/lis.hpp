#ifndef LIB_SEQUENCE_LIS_HPP
#define LIB_SEQUENCE_LIS_HPP 1

#include <bits/stdc++.h>

namespace lib::sequence {

template <class T> int lis(std::vector<T>& a, bool can_weakly_increase = true) {
    const T inf = std::numeric_limits<T>::max();

    int n = int(a.size());
    std::vector<T> dp(n, inf);

    for (int i = 0; i < n; ++i) {
        if(can_weakly_increase) {
            *std::upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
        } else {
            *std::lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
        }
    }

    return std::lower_bound(dp.begin(), dp.end(), inf) - dp.begin();
}

}  // namespace lib::sequence

#endif  // LIB_SEQUENCE_LIS_HPP
