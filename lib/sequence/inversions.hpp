#ifndef LIB_SEQUENCE_INVERSIONS_HPP
#define LIB_SEQUENCE_INVERSIONS_HPP 1

#include <bits/stdc++.h>
#include "./fenwick_tree.hpp"

namespace lib::sequence {

template <class T> long long inversions(std::vector<T>& a) {
    int n = (int) a.size();

    std::set<T> set;
    for(int i = 0; i < n; ++i) {
        set.insert(a[i]);
    }
    std::unordered_map<T, int> v2i;
    for(T v:set) {
        v2i[v] = (int) v2i.size();
    }

    std::vector<T> b(n);
    for(int i = 0; i < n; ++i) {
        b[i] = T(v2i[a[i]]);
    }

    lib::sequence::fenwick_tree<int> ft(n);
    long long count = 0;
    for(int i = 0; i < n; ++i) {
        ft.add(b[i], 1);
        count += ft.sum(b[i] + 1, n);
    }
    return count;
}

}  // namespace lib::sequence

#endif  // LIB_SEQUENCE_INVERSIONS_HPP
