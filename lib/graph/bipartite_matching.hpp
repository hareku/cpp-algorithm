#ifndef LIB_GRAPH_BIPARTITE_MATCHING_HPP
#define LIB_GRAPH_BIPARTITE_MATCHING_HPP 1

#include <bits/stdc++.h>
#include "maxflow.hpp"

namespace lib::graph {

struct bipartite_matching_graph {
  public:
    bipartite_matching_graph(int l, int r) : _l(l), _r(r), _s(l + r), _t(l + r + 1), mf_graph(l + r + 2) {
        for(int i = 0; i < _l; ++i) {
            mf_graph.add_edge(_s, i, 1);
        }
        for(int i = 0; i < _r; ++i) {
            mf_graph.add_edge(i + _l, _t, 1);
        }
    }

    void add_edge(int l, int r) {
        mf_graph.add_edge(l, r + _l, 1);
    }

    int bipartite_matching() {
        return mf_graph.flow(_s, _t);
    }

    std::vector<std::pair<int, int>> matches() {
        std::vector<std::pair<int, int>> res;

        auto edges = mf_graph.edges();
        for(auto& e : edges) {
            if(e.from == _s || e.to == _t || e.flow == 0) continue;
            res.push_back({e.from, e.to - _l});
        }

        return res;
    }

  private:
    int _l, _r;
    int _s, _t;
    lib::graph::maxflow_graph<int> mf_graph;
};

}  // namespace lib::graph

#endif  // LIB_GRAPH_BIPARTITE_MATCHING_HPP
