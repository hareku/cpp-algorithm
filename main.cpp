#include <bits/stdc++.h>
#include "utils/macro.hpp"
#include "utils/debug.hpp"
#include "mylib/dijkstra.hpp"
#include "mylib/bellman_ford.hpp"
// #include <atcoder/all>
using namespace std;
// const long long MOD = 1e9+7;
// const long long MOD = 998244353;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N,M,P; cin >> N >> M >> P;

    mylib::dijkstra_graph<int> froms_g(N);
    mylib::dijkstra_graph<int> fromn_g(N);

    vector<int> A(M), B(M), C(M);
    rep(i, M) {
        int a,b,c; cin >> a >> b >> c;
        --a, --b;
        froms_g.add_edge(a, b, 1);
        fromn_g.add_edge(b, a, 1);

        A[i] = a;
        B[i] = b;
        C[i] = c;
    }

    auto froms_res = froms_g.dijkstra(0);
    auto fromn_res = fromn_g.dijkstra(N - 1);
    auto froms_seen = get<0>(froms_res);
    auto fromn_seen = get<0>(fromn_res);

    mylib::bellman_ford_graph<long long> g(N);
    rep(i, M) {
        if(froms_seen[A[i]] && fromn_seen[A[i]] && froms_seen[B[i]] && fromn_seen[B[i]]) {
            g.add_edge(A[i], B[i], -1LL * C[i] + P);
        }
    }

    auto res = g.bellman_ford(0, INFLL);
    if(!res.first) {
        print(-1);
        return 0;
    }

    print(max(0LL, res.second[N - 1] * -1LL));
    return 0;
}
