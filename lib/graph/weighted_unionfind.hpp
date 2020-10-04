#ifndef LIB_GRAPH_WEIGHTED_UNIONFIND_HPP
#define LIB_GRAPH_WEIGHTED_UNIONFIND_HPP 1

#include <bits/stdc++.h>

namespace lib::graph {

template <class Weight> struct weighted_unionfind {
  public:
    weighted_unionfind(int n) : _n(n), par(n), rank(n, 0), diff_weight(n, 0) {
        for (int i = 0; i < n; ++i) par[i] = i;
    }

    int root(int x) {
        assert(0 <= x && x < _n);
        if (par[x] == x) return x;

        int r = root(par[x]);
        diff_weight[x] += diff_weight[par[x]];
        return par[x] = r;
    }

    Weight weight(int x) {
        assert(0 <= x && x < _n);
        root(x);
        return diff_weight[x];
    }

    bool same(int x, int y) {
        assert(0 <= x && x < _n);
        assert(0 <= y && y < _n);
        return root(x) == root(y);
    }

    bool merge(int x, int y, Weight w) {
        assert(0 <= x && x < _n);
        assert(0 <= y && y < _n);

        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) std::swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Weight diff(int x, int y) {
        assert(0 <= x && x < _n);
        assert(0 <= y && y < _n);
        return weight(y) - weight(x);
    }

  private:
    int _n;
    std::vector<int> par;
    std::vector<int> rank;
    std::vector<Weight> diff_weight;
};

}  // namespace lib::graph

#endif  // LIB_GRAPH_WEIGHTED_UNIONFIND_HPP
