#ifndef LIB_GRAPH_TREE_DIAMETER_HPP
#define LIB_GRAPH_TREE_DIAMETER_HPP 1

#include <bits/stdc++.h>

namespace lib::graph {

template <class Cost> struct tree_diameter_graph {
  public:
    tree_diameter_graph() : _n(0) {}
    tree_diameter_graph(int n) : _n(n), g(n) {}

    void add_edge(int from, int to, Cost cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cost);
        g[from].push_back(_edge{to, cost});
    }

    Cost tree_diameter() {
        auto res1 = max_cost(0);
        auto res2 = max_cost(res1.second);
        return res2.first;
    }

  private:
    std::pair<Cost, int> max_cost(int s) {
        struct Q {
            int v;
            Cost cost;
        };

        std::queue<Q> q;
        std::pair<Cost, int> res = {0, 0};
        std::vector<bool> seen(_n, false);

        q.push(Q{s, Cost{0}});

        while(!q.empty()) {
            Q c = q.front();
            q.pop();

            if(seen[c.v]) continue;
            seen[c.v] = true;

            if(c.cost > res.first) {
                res.first = c.cost;
                res.second = c.v;
            }

            for(_edge& e : g[c.v]) {
                if(!seen[e.to]) {
                    q.push(Q{e.to, c.cost + e.cost});
                }
            }
        }

        return res;
    }

    int _n;
    struct _edge {
        int to;
        Cost cost;
    };
    std::vector<std::vector<_edge>> g;
};

}  // namespace lib::graph

#endif  // LIB_GRAPH_TREE_DIAMETER_HPP
