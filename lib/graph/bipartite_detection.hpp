#ifndef LIB_GRAPH_BIPARTITE_DETECTION_HPP
#define LIB_GRAPH_BIPARTITE_DETECTION_HPP 1

#include <bits/stdc++.h>

namespace lib::graph {

struct bipartite_detection_graph {
  public:
    bipartite_detection_graph(int n) : _n(n), g(n) {}

    void add_edge(int from, int to, bool bidirection = false) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        g[from].push_back(_edge{to});
        if(bidirection) {
            g[to].push_back(_edge{from});
        }
    }

    // is_bipartite detects whether the given graph is bipartite.
    // About the returned pair, first is whether the given graph is bipartite,
    // and second represents colors of each edge.
    // Time complexity is O(N).
    std::pair<bool, std::vector<bool>> is_bipartite() {
        std::vector<bool> seen(_n, false);
        std::vector<bool> evenodd(_n);

        auto dfs = [&](auto self, int s, bool odd) {
            seen[s] = true;
            evenodd[s] = odd;

            for(_edge& e : g[s]) {
                if(seen[e.to] && evenodd[e.to] != !odd) {
                    return false;
                }

                if(!seen[e.to]) {
                    bool ok = self(self, e.to, !odd);
                    if(!ok) return false;
                }
            }

            return true;
        };

        bool ok = true;
        for(int i = 0; i < _n; i++) {
            if(seen[i]) continue;
            if(!dfs(dfs, i, false)) {
                ok = false;
                break;
            }
        }
        return std::make_pair(ok, evenodd);
    }

  private:
    int _n;
    struct _edge {
        int to;
    };
    std::vector<std::vector<_edge>> g;
};

}  // namespace lib::graph

#endif  // LIB_GRAPH_BIPARTITE_DETECTION_HPP
