#ifndef LIB_GRAPH_BELLMAN_FORD_HPP
#define LIB_GRAPH_BELLMAN_FORD_HPP 1

#include <bits/stdc++.h>

namespace lib::graph {

template <class Cost> struct bellman_ford_graph {
  public:
    bellman_ford_graph(int n) : _n(n) {}

    void add_edge(int from, int to, Cost cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        edges.push_back(_edge{from, to, cost});
    }

    std::pair<bool, std::vector<Cost>> bellman_ford(int s, Cost inf) {
        assert(0 <= s && s < _n);
        std::vector<Cost> dist(_n, inf);
        dist[s] = Cost{0};

        for(int i = 0; i < _n; i++) {
            for(auto& e : edges) {
                if (dist[e.from] < inf && dist[e.to] > dist[e.from] + e.cost) {
                    dist[e.to] = dist[e.from] + e.cost;
                    if (i == _n - 1) {
                        return std::make_pair(false, dist);
                    }
                }
            }
        }

        return std::make_pair(true, dist);
    }

  private:
    int _n;
    struct _edge {
        int from, to;
        Cost cost;
    };
    std::vector<_edge> edges;
};

}  // namespace lib::graph

#endif  // LIB_GRAPH_BELLMAN_FORD_HPP
