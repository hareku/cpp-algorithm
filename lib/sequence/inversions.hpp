#ifndef LIB_SEQUENCE_INVERSIONS_HPP
#define LIB_SEQUENCE_INVERSIONS_HPP 1

#include <bits/stdc++.h>
#include "./fenwick_tree.hpp"
#include "./compressor.hpp"

namespace lib::sequence {

template <class T> long long inversions(std::vector<T>& a) {
    // compress values for fenwick_tree
    compressor<T> cmp;
    for(T v:a) {
        cmp.add(v);
    }
    auto v2i = cmp.compress();

    int n = (int) a.size();
    lib::sequence::fenwick_tree<int> ft(n);
    long long count = 0;
    for(int i = 0; i < n; ++i) {
        ft.add(v2i[a[i]], 1);
        count += ft.sum(v2i[a[i]] + 1, n);
    }
    return count;
}

}  // namespace lib::sequence

#endif  // LIB_SEQUENCE_INVERSIONS_HPP
