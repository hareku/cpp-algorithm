#ifndef LIB_SORT_SELECTION_SORT_HPP
#define LIB_SORT_SELECTION_SORT_HPP 1

#include <bits/stdc++.h>

namespace lib::sort {

template <class T> int selection_sort(std::vector<T>& a) {
    int n = int(a.size());
    int cnt = 0;

    for(int i = 0; i < n - 1; i++) {
        int min_i = i;
        for(int j = i + 1; j < n; j++) {
            if(a[min_i] > a[j]) {
                min_i = j;
            }
        }
        if(i != min_i) {
            std::swap(a[i], a[min_i]);
            ++cnt;
        }
    }

    return cnt;
}

}  // namespace lib::sort

#endif  // LIB_SORT_SELECTION_SORT_HPP
