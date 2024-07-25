#ifndef LIB_GRAPH_CYCLE_DETECTION_HPP
#define LIB_GRAPH_CYCLE_DETECTION_HPP 1

#include <bits/stdc++.h>
#include "./unionfind.hpp"
#include "../sequence/compressor.hpp"

namespace lib::graph {

struct cycle_detection_graph {
  public:
    cycle_detection_graph(int n) : _n(n), g(n) {}

    void add_edge(int from, int to) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        g[from].push_back(_edge{to});
    }

    std::vector<int> detect() {
        std::vector<int> his;
        std::vector<bool> seen(_n, false);
        std::vector<bool> seen_children(_n, false);
        int start;

        auto dfs = [&](auto self, int cur) {
            seen[cur] = true;
            his.push_back(cur);

            for(auto& e : g[cur]) {
                if(seen_children[e.to]) continue;

                if(seen[e.to] && !seen_children[e.to]) {
                    start = e.to;
                    return true;
                }

                bool detected = self(self, e.to);
                if(detected) {
                    return true;
                }
            }

            his.pop_back();
            seen_children[cur] = true;
            return false;
        };

        auto make_cycle = [&]() {
            std::vector<int> cycle;
            int i = 0;
            while(his[i] != start) ++i;
            for(; i < int(his.size()); ++i) {
                cycle.push_back(his[i]);
            }
            return cycle;
        };

        for(int i = 0; i < _n; ++i) {
            if(seen[i]) continue;
            if(dfs(dfs, i)) {
                return make_cycle();
            }
        }

        return {};
    }

  private:
    int _n;
    struct _edge {
        int to;
    };
    std::vector<std::vector<_edge>> g;
};

struct all_cycle_detection_graph {
  public:
    all_cycle_detection_graph(int n) : _n(n), g(n) {}

    void add_edge(int from, int to) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        g[from].push_back(_edge{to});
    }

    std::vector<std::vector<int>> all_cycles() {
        lib::graph::unionfind uf(_n);
        for(int i = 0; i < _n; i++) {
            for(_edge& e : g[i]) {
                uf.merge(i, e.to);
            }
        }

        std::vector<std::vector<int>> cycles;

        for(std::vector<int>& group : uf.groups()) {
            lib::sequence::compressor<int> cmp;
            for(int i : group) {
                cmp.add(i);
            }

            int m = (int) group.size();
            cycle_detection_graph cg(m);

            std::unordered_map<int, int> v2i = cmp.compress();
            std::unordered_map<int, int> i2v = cmp.reverse(v2i);
            for(int i : group) {
                for(_edge& e : g[i]) {
                    cg.add_edge(v2i[i], v2i[e.to]);
                }
            }

            auto cycle = cg.detect();
            if(cycle.size() == 0) {
                continue;
            }
            vector<int> normalized;
            for(int i : cycle) {
                normalized.push_back(i2v[i]);
            }
            cycles.push_back(normalized);
        }

        return cycles;
    }

  private:
    int _n;
    struct _edge {
        int to;
    };
    std::vector<std::vector<_edge>> g;
};

}  // namespace lib::graph

#endif  // LIB_GRAPH_CYCLE_DETECTION_HPP
