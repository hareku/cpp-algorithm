#ifndef LIB_GRAPH_LCA_HPP
#define LIB_GRAPH_LCA_HPP 1

#include <bits/stdc++.h>
#include "../sequence/segtree.hpp"

namespace lib::graph {

struct S {
    int node, depth;
};
S _op(S a, S b) { return a.depth < b.depth ? a : b; }
S _e() { return {0, INT_MAX}; }

struct lca_tree {
  public:
    lca_tree() : _n(0) {}
    lca_tree(int n) : _n(n), g(n) {}

    void add_edge(int from, int to) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        g[from].push_back(_edge{to});
    }

    int find_root() {
        std::vector<bool> is_root(_n, true);
        for(int i = 0; i < _n; ++i) {
            for(int j = 0; j < int(g[i].size()); ++j) {
                is_root[g[i][j].to] = false;
            }
        }
        for(int i = 0; i < _n; ++i) {
            if(is_root[i]) return i;
        }
        return -1;
    }

    void build() {
        assert(!built);
        built = true;

        std::vector<S> order;
        first.resize(_n);
        first.assign(_n, -1);

        auto dfs = [&](auto self, int a, int depth) {
            if(0) return;

            order.push_back({a, depth});
            if(first[a] == -1) {
                first[a] = int(order.size() - 1);
            }

            for(int i = 0; i < int(g[a].size()); ++i) {
                self(self, g[a][i].to, depth + 1);
                order.push_back({a, depth});
            }
        };

        int root = find_root();
        assert(0 <= root && root < _n);
        dfs(dfs, root, 0);

        seg = lib::sequence::segtree<S, _op, _e>(order);
        return;
    }

    int lca(int a, int b) {
        assert(built);
        int l = first[a], r = first[b];
        if(l > r) std::swap(l, r);
        return seg.prod(l, r + 1).node;
    }

  private:
    int _n;
    struct _edge {
        int to;
    };
    bool built = false;
    std::vector<std::vector<_edge>> g;
    std::vector<int> first;
    lib::sequence::segtree<S, _op, _e> seg;
};

}  // namespace lib::graph

#endif  // LIB_GRAPH_LCA_HPP
