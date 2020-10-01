#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include <bits/stdc++.h>
#include "kruskal.hpp"
using namespace std;

int main() {
    int N,M; cin >> N >> M;

    mylib::kruskal_graph<long long> g(N);

    for(int i = 0; i < M; ++i) {
        int a,b; cin >> a >> b;
        long long c; cin >> c;
        g.add_edge(a, b, c);
    }

    long long min_cost = g.kruskal();

    cout << min_cost << endl;

    return 0;
}
