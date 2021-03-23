#ifndef LIB_GRAPH_WARSHALL_FLOYD_HPP
#define LIB_GRAPH_WARSHALL_FLOYD_HPP 1

#include <bits/stdc++.h>

namespace lib::graph {

template <class Cost> struct warshall_floyd_graph {
  public:
    warshall_floyd_graph() : _n(0) {}
    warshall_floyd_graph(int n) : _n(n), _inf(std::numeric_limits<Cost>::max()), g(n, std::vector<Cost>(n, _inf)) {}
    using distance_table = std::vector<std::vector<Cost>>;

    void update_edge(int from, int to, Cost cost, bool bidirection = false) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);

        g[from][to] = std::min(g[from][to], cost);
        if(bidirection) {
            g[to][from] = std::min(g[to][from], cost);
        }
    }

    // warshall_floyd returns a pair.
    // The first represents whether a cycle was detected or not.
    // The second is a vector in vector, its [i][j] represents min cost between i and j.
    // If a min cost is equals inf(), it means to unable to reach from i to j.
    // This function's time complexity is O(N^3).
    std::pair<bool, distance_table> warshall_floyd() {
        distance_table res = g;
        for(int i = 0; i < _n; ++i) {
            res[i][i] = Cost{0};
        }

        for(int k = 0; k < _n; ++k) {
            for(int i = 0; i < _n; ++i) {
                for(int j = 0; j < _n; ++j) {
                    if(i == j && res[i][i] < 0) {
                        return std::make_pair(false, distance_table{});
                    }

                    if(res[i][k] != _inf && res[k][j] != _inf) {
                        res[i][j] = std::min(res[i][j], res[i][k] + res[k][j]);
                    }
                }
            }
        }

        return std::make_pair(true, res);
    }

    Cost inf() {
        return _inf;
    }

    // This function's time complexity is O(N^2).
    void update_min_distance(distance_table& table, int from, int to, Cost cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert((int)table.size() == _n);

        auto get_cost = [&table](int from, int to)->Cost {
            if(from == to) {
                return Cost{0};
            }

            return table[from][to];
        };

        for(int i = 0; i < _n; ++i) {
            for(int j = 0; j < _n; ++j) {
                if(i == j) {
                    continue;
                }

                if(get_cost(i, from) == _inf || get_cost(to, j) == _inf) continue;
                Cost new_cost = get_cost(i, from) + get_cost(to, j) + cost;

                table[i][j] = std::min(table[i][j], new_cost);
            }
        }
    }

  private:
    int _n;
    Cost _inf;
    distance_table g;
};

}  // namespace lib::graph

#endif  // LIB_GRAPH_WARSHALL_FLOYD_HPP
