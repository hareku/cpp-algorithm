#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"
#include <bits/stdc++.h>
#include "../../lib/graph/bellman_ford.hpp"
using namespace std;

int main() {
    int N,M; cin >> N >> M;
    int r; cin >> r;

    lib::graph::bellman_ford_graph<long long> g(N);

    for(int i = 0; i < M; ++i) {
        int s,t;
        long long d;
        cin >> s >> t >> d;
        g.add_edge(s, t, d);
    }

    long long inf = (1LL << 60);
    auto result = g.bellman_ford(r, inf);

    if(!result.first) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    for(int i = 0; i < N; ++i) {
        if(result.second[i] == inf) {
            cout << "INF" << endl;
        } else {
            cout << result.second[i] << endl;
        }
    }
    return 0;
}
