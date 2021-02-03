#ifndef LIB_GRAPH_KRUSKAL_HPP
#define LIB_GRAPH_KRUSKAL_HPP 1

#include <bits/stdc++.h>
#include "unionfind.hpp"

namespace lib::graph {

template <class Cost> struct kruskal_graph {
  public:
    kruskal_graph(int n) : _n(n) {}

    void add_edge(int from, int to, Cost cost, bool bidirection = false) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        edges.push_back(_edge{from, to, cost});
        if(bidirection) {
            edges.push_back(_edge{to, from, cost});
        }
    }

    Cost kruskal() {
        lib::graph::unionfind uf(_n);
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

}  // namespace lib::graph

#endif  // LIB_GRAPH_KRUSKAL_HPP
