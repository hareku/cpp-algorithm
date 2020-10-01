#ifndef MYLIB_DIJKSTRA_HPP
#define MYLIB_DIJKSTRA_HPP 1

#include <bits/stdc++.h>

namespace mylib {

template <class Cost> struct dijkstra_graph {
  public:
    dijkstra_graph() : _n(0) {}
    dijkstra_graph(int n) : _n(n), g(n) {}

    void add_edge(int from, int to, Cost cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cost);
        g[from].push_back(_edge{to, cost});
    }

    auto dijkstra(int s) {
        assert(0 <= s && s < _n);

        struct Q {
            Q(Cost cost, int to) : cost(cost), to(to) {}

            Cost cost;
            int to;
            bool operator<(Q r) const { return cost > r.cost; }
        };
        std::priority_queue<Q> pq;

        std::vector<bool> seen(_n, false);
        std::vector<Cost> dist(_n);
        std::vector<int> from(_n);

        pq.push(Q(Cost{0}, s));
        seen[s] = true;
        dist[s] = Cost{0};

        while (!pq.empty()) {
            Q q = pq.top();
            pq.pop();

            if(seen[q.to] && dist[q.to] < q.cost) continue;

            for (int i = 0; i < int(g[q.to].size()); i++) {
                _edge e = g[q.to][i];
                Cost cost = q.cost + e.cost;

                if(!seen[e.to] || dist[e.to] > cost) {
                    seen[e.to] = true;
                    dist[e.to] = cost;
                    from[e.to] = q.to;
                    pq.push(Q(cost, e.to));
                }
            }
        }

        return std::make_tuple(seen, dist, from);
    }

  private:
    int _n;
    struct _edge {
        int to;
        Cost cost;
    };
    std::vector<std::vector<_edge>> g;
};

}  // namespace mylib

#endif  // MYLIB_DIJKSTRA_HPP
