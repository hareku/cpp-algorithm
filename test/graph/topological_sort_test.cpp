// TODO: https://github.com/online-judge-tools/verification-helper/issues/30
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"
#include <bits/stdc++.h>
#include "../../lib/graph/topological_sort.hpp"
using namespace std;

int main() {
    int N,M; cin >> N >> M;

    lib::graph::topological_sort_graph g(N);

    for(int i = 0; i < M; ++i) {
        int a,b; cin >> a >> b;
        g.add_edge(a, b);
    }

    auto result = g.topological_sort();

    for(auto v : result) {
        cout << v << endl;
    }

    return 0;
}
