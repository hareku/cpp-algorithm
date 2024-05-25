#ifndef LIB_GRAPH_CBT_HPP
#define LIB_GRAPH_CBT_HPP 1

#include <bits/stdc++.h>

namespace lib::graph {

long long _powll(long long a, long long e) {
    if(e == 0) return 1;
    ll res = a;
    rep(i,e-1) res *= a;
    return res;
}

// the depth of "i" in a complete binary tree
long long cbt_depth(long long i) {
    assert(i >= 1);
    int d = 0;
    while(i) {
        i >>= 1;
        d++;
    }
    return d;
}

long long cbt_left_upper_bound(long long depth) {
    assert(depth >= 1);
    return _powll(2,depth-1) + _powll(2,depth-2) - 1;
}

long long cbt_right_upper_bound(long long depth) {
    assert(depth >= 1);
    return _powll(2,depth) - 1;
}

}  // namespace lib::graph

#endif  // LIB_GRAPH_CBT_HPP
