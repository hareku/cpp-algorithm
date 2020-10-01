#ifndef MYLIB_TOPOLOGICAL_SORT_HPP
#define MYLIB_TOPOLOGICAL_SORT_HPP 1

#include <bits/stdc++.h>

namespace mylib {

struct topological_sort_graph {
  public:
    topological_sort_graph() : _n(0) {}
    topological_sort_graph(int n) : _n(n), g(n), indegree(n, 0) {}

    void add_edge(int from, int to) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        g[from].push_back(_edge{to});
        ++indegree[to];
    }

    std::vector<int> topological_sort() {
        std::stack<int> st;
        for(int i = 0; i < _n; ++i) {
            if(indegree[i] == 0) {
                st.push(i);
            }
        }

        std::vector<int> res;

        while(!st.empty()) {
            int v = st.top();
            st.pop();

            res.push_back(v);

            for(_edge& e : g[v]) {
                --indegree[e.to];
                if(indegree[e.to] == 0) {
                    st.push(e.to);
                }
            }
        }

        return res;
    }

  private:
    int _n;
    struct _edge {
        int to;
    };
    std::vector<std::vector<_edge>> g;
    std::vector<int> indegree;
};

}  // namespace mylib

#endif  // MYLIB_TOPOLOGICAL_SORT_HPP
