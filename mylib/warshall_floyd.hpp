#include <bits/stdc++.h>

namespace mylib {

template <class Cost> struct warshall_floyd_graph {
  public:
    warshall_floyd_graph() : _n(0) {}
    warshall_floyd_graph(int n, Cost inf) : _n(n), _inf(inf), g(n, std::vector<Cost>(n, inf)) {}

    void update_edge(int from, int to, Cost cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        g[from][to] = cost;
    }

    std::pair<bool, std::vector<std::vector<Cost>>> warshall_floyd() {
        std::vector<std::vector<Cost>> res = g;
        for(int i = 0; i < _n; ++i) {
            res[i][i] = Cost{0};
        }

        for(int k = 0; k < _n; ++k) {
            for(int i = 0; i < _n; ++i) {
                for(int j = 0; j < _n; ++j) {
                    if(i == j && res[i][i] < 0) {
                        return std::make_pair(false, std::vector<std::vector<Cost>>{});
                    }

                    if(res[i][k] != _inf && res[k][j] != _inf) {
                        res[i][j] = std::min(res[i][j], res[i][k] + res[k][j]);
                    }
                }
            }
        }

        return std::make_pair(true, res);
    }

  private:
    int _n;
    Cost _inf;
    std::vector<std::vector<Cost>> g;
};

}  // namespace mylib
