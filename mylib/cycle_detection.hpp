#ifndef MYLIB_CYCLE_DETECTION_HPP
#define MYLIB_CYCLE_DETECTION_HPP 1

#include <bits/stdc++.h>

namespace mylib {

struct cycle_detection_graph {
  public:
    cycle_detection_graph() : _n(0) {}
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

}  // namespace mylib

#endif  // MYLIB_CYCLE_DETECTION_HPP
