#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"
#include <bits/stdc++.h>
#include "../../lib/graph/cycle_detection.hpp"
using namespace std;

int main() {
    int N,M; cin >> N >> M;

    lib::graph::cycle_detection_graph g(N);

    std::unordered_map<int, std::unordered_map<int, int>> ids;
    for(int i = 0; i < M; ++i) {
        int u,v; cin >> u >> v;
        g.add_edge(u, v);
        ids[u][v] = i;
    }

    auto result = g.detect();

    int res_n = int(result.size());

    if(res_n == 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << res_n << endl;
    for(int i = 0; i < res_n; ++i) {
        auto id = i == res_n - 1 ? ids[result[i]][result[0]] : ids[result[i]][result[i + 1]];
        cout << id << endl;
    }
    return 0;
}
