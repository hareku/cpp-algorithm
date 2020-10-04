#ifndef LIB_SORT_INSERTION_SORT_HPP
#define LIB_SORT_INSERTION_SORT_HPP 1

#include <bits/stdc++.h>

namespace lib::sort {

template <class T> std::vector<std::vector<T>> insertion_sort(std::vector<T>& a) {
    int n = int(a.size());
    std::vector<std::vector<T>> res;

    res.push_back(a);

    for(int i = 1; i < n; i++) {
        int v = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        res.push_back(a);
    }

    return res;
}

}  // namespace lib::sort

#endif  // LIB_SORT_INSERTION_SORT_HPP
