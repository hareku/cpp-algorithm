#ifndef MYLIB_KRUSKAL_HPP
#define MYLIB_KRUSKAL_HPP 1

#include <bits/stdc++.h>
#include "unionfind.hpp"

namespace mylib {

template <class Cost> struct kruskal_graph {
  public:
    kruskal_graph(int n) : _n(n) {}

    void add_edge(int from, int to, Cost cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        edges.push_back(_edge{from, to, cost});
    }

    Cost kruskal() {
        mylib::unionfind uf(_n);
        Cost cost = 0;
        std::sort(edges.begin(), edges.end());

        for(_edge& e : edges) {
            if(!uf.same(e.from, e.to)) {
                uf.merge(e.from, e.to);
                cost += e.cost;
            }
        }

        return cost;
    }

  private:
    int _n;
    struct _edge {
        int from, to;
        Cost cost;
        bool operator<(_edge r) const { return cost < r.cost; }
    };
    std::vector<_edge> edges;
};

}  // namespace mylib

#endif  // MYLIB_KRUSKAL_HPP
