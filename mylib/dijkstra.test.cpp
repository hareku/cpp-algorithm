#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include <bits/stdc++.h>
#include "dijkstra.hpp"
using namespace std;

int main() {
    int N,M; cin >> N >> M;
    int s,t; cin >> s >> t;

    mylib::dijkstra_graph<long long> dg(N);

    for(int i = 0; i < M; ++i) {
        int a,b; cin >> a >> b;
        long long c; cin >> c;
        dg.add_edge(a, b, c);
    }

    auto result = dg.dijkstra(s);
    auto seen = get<0>(result);
    auto dist = get<1>(result);
    auto from = get<2>(result);

    if(!seen[t]) {
        cout << -1 << endl;
        return 0;
    }

    vector<pair<int, int>> ans;
    int cur = t;
    while(cur != s) {
        ans.push_back({from[cur], cur});
        cur = from[cur];
    }

    cout << dist[t] << " " << ans.size() << endl;
    for(int i = (int)ans.size() - 1; i >= 0; --i) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}
