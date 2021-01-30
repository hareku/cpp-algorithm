#ifndef LIB_GRAPH_HAMILTONIAN_PATH_HPP
#define LIB_GRAPH_HAMILTONIAN_PATH_HPP 1

#include <bits/stdc++.h>

namespace lib::graph {

template <class Cost> struct hamiltonian_path_graph {
  public:
    hamiltonian_path_graph() : _n(0) {}
    hamiltonian_path_graph(int n) : _n(n), _inf(std::numeric_limits<Cost>::max()), g(n, std::vector<Cost>(n, _inf)) {}

    void update_edge(int from, int to, Cost cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cost);
        g[from][to] = std::min(g[from][to], cost);
    }

    std::pair<bool, Cost> shortest_hamiltonian_path() {
        int size = 1 << _n;
        std::vector<std::vector<Cost>> dp(size, std::vector<Cost>(_n, _inf));
        for(int i = 0; i < _n; ++i) {
            dp[(1 << i)][i] = 0;
        }

        for(int bit = 1; bit < size; bit++) {
            for(int i = 0; i < _n; i++) {
                if(bit & (1 << i)) {
                    const int from_bit = bit ^ (1 << i);
                    for(int j = 0; j < _n; j++) {
                        if(from_bit & (1 << j) && dp[from_bit][j] != _inf && g[i][j] != _inf) {
                            dp[bit][i] = std::min(dp[bit][i], dp[from_bit][j] + g[j][i]);
                        }
                    }
                }
            }
        }

        Cost ans = *std::min_element(dp.back().begin(), dp.back().end());
        return {ans != _inf, ans};
    }

  private:
    int _n;
    Cost _inf;
    std::vector<std::vector<Cost>> g;
};

}  // namespace lib::graph

#endif  // LIB_GRAPH_HAMILTONIAN_PATH_HPP
