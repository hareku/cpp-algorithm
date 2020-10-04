#ifndef LIB_SORT_BUBBLE_SORT_HPP
#define LIB_SORT_BUBBLE_SORT_HPP 1

#include <bits/stdc++.h>

namespace lib::sort {

template <class T> int bubble_sort(std::vector<T>& a) {
    int n = int(a.size());
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = n - 1; j > i; j--) {
            if(a[j - 1] > a[j]) {
                std::swap(a[j], a[j - 1]);
                ++cnt;
            }
        }
    }

    return cnt;
}

}  // namespace lib::sort

#endif  // LIB_SORT_BUBBLE_SORT_HPP
