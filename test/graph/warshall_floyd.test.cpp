#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include <bits/stdc++.h>
#include "../../lib/graph/warshall_floyd.hpp"
using namespace std;

int main() {
    int N,M; cin >> N >> M;

    lib::graph::warshall_floyd_graph<long long> g(N);
    long long inf = g.inf();

    for(int i = 0; i < M; ++i) {
        int a,b; cin >> a >> b;
        long long c; cin >> c;
        g.update_edge(a, b, c);
    }

    auto result = g.warshall_floyd();

    if(!result.first) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(result.second[i][j] == inf) {
                cout << "INF";
            } else {
                cout << result.second[i][j];
            }

            if(j == N - 1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }

    return 0;
}
