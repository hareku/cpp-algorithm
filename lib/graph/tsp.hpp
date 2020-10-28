#ifndef LIB_GRAPH_TSP_HPP
#define LIB_GRAPH_TSP_HPP 1

#include <bits/stdc++.h>

namespace lib::graph {

template <class Cost> struct tsp_graph {
  public:
    tsp_graph() : _n(0) {}
    tsp_graph(int n) : _n(n), _inf(std::numeric_limits<Cost>::max()), g(n, std::vector<Cost>(n, _inf)) {}

    void update_edge(int from, int to, Cost cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cost);
        g[from][to] = std::min(g[from][to], cost);
    }

    std::pair<bool, Cost> tsp(int s, bool return_s = true) {
        assert(0 <= s && s < _n);
        int size = 1 << _n;
        std::vector<std::vector<Cost>> dp(size, std::vector<Cost>(_n, -1));

        auto rec = [&](auto self, int bit, int pos) {
            if(dp[bit][pos] != -1) {
                return dp[bit][pos];
            }

            if(bit == size - 1 && pos == s) {
                return dp[bit][pos] = Cost(0);
            }

            Cost m = _inf;
            for(int i = 0; i < _n; ++i) {
                if(!(bit >> i & 1) && g[pos][i] != _inf) {
                    Cost next = self(self, bit | (1 << i), i);
                    if(!return_s && next == 0 && i == s) {
                        m = 0;
                    } else if(next != _inf) {
                        m = std::min(m, next + g[pos][i]);
                    }
                }
            }

            dp[bit][pos] = m;
            return m;
        };

        Cost minc = rec(rec, 0, s);
        bool found = minc != _inf;
        return std::make_pair(found, minc);
    }

  private:
    int _n;
    Cost _inf;
    std::vector<std::vector<Cost>> g;
};

}  // namespace lib::graph

#endif  // LIB_GRAPH_TSP_HPP
