#ifndef LIB_GRAPH_LCA_HPP
#define LIB_GRAPH_LCA_HPP 1

#include <bits/stdc++.h>
#include "../sequence/segtree.hpp"

namespace lib::graph {
    namespace _internal {
        struct S {
            int node, depth;
        };
        S _op(S a, S b) { return a.depth < b.depth ? a : b; }
        S _e() { return {0, INT_MAX}; }
    }

// ref: https://tjkendev.github.io/procon-library/python/graph/lca-segment-tree.html
struct lca_tree {
  public:
    lca_tree(int n) : _n(n), g(n), _root(-1) {
        first.assign(n, -1);
    }

    void add_edge(int from, int to) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        g[from].push_back(_edge{to});
    }

    // root gets root node id.
    // If you call this prev build(), returns -1.
    int root() {
        return _root;
    }

    // Time complexity is O(N);
    void build() {
        assert(!built);
        built = true;

        find_root();
        assert(0 <= _root && _root < _n);

        std::vector<_internal::S> order;
        auto dfs = [&](auto self, int a, int depth)->void {
            order.push_back({a, depth});
            if(first[a] == -1) {
                first[a] = int(order.size() - 1);
            }

            for(int i = 0; i < int(g[a].size()); ++i) {
                self(self, g[a][i].to, depth + 1);
                order.push_back({a, depth});
            }
        };

        dfs(dfs, _root, 0);

        seg = lib::sequence::segtree<_internal::S, _internal::_op, _internal::_e>(order);
        return;
    }

    // lca gets lowest common ancestor' node id.
    // Time complexity is O(log N);
    int lca(int a, int b) {
        assert(built);
        int l = first[a], r = first[b];
        if(l > r) std::swap(l, r);
        return seg.prod(l, r + 1).node;
    }

  private:
    // find_root sets root node id to _root.
    void find_root() {
        std::vector<bool> is_root(_n, true);
        for(int i = 0; i < _n; ++i) {
            for(int j = 0; j < int(g[i].size()); ++j) {
                is_root[g[i][j].to] = false;
            }
        }
        for(int i = 0; i < _n; ++i) {
            if(is_root[i]) {
                _root = i;
                return;
            }
        }
    }

    int _n;
    int _root;
    struct _edge {
        int to;
    };
    bool built = false;
    // g represents a graph by adjacency list.
    std::vector<std::vector<_edge>> g;
    // first has the order in which the node first appeared
    // when searching with dfs.
    std::vector<int> first;
    // seg provides ranged min query for depth.
    lib::sequence::segtree<_internal::S, _internal::_op, _internal::_e> seg;
};

}  // namespace lib::graph

#endif  // LIB_GRAPH_LCA_HPP
