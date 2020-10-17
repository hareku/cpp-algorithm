#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A"
#include <bits/stdc++.h>
#include "../../lib/graph/tsp.hpp"
using namespace std;

int main() {
    int N,M; cin >> N >> M;

    lib::graph::tsp_graph<int> g(N);

    for(int i = 0; i < M; ++i) {
        int s,t,d; cin >> s >> t >> d;
        g.update_edge(s, t, d);
    }

    int ans = INT_MAX;
    for(int i = 0; i < N; ++i) {
        auto res = g.tsp(i);
        if(res.first) {
            ans = min(ans, res.second);
        }
    }

    if(ans == INT_MAX) {
        ans = -1;
    }

    cout << ans << endl;
    return 0;
}
