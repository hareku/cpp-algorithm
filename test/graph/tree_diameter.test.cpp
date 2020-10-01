#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"
#include <bits/stdc++.h>
#include "../../lib/graph/tree_diameter.hpp"
using namespace std;

int main() {
    int N; cin >> N;

    lib::graph::tree_diameter_graph<int> g(N);

    for(int i = 0; i < N - 1; ++i) {
        int a,b; cin >> a >> b;
        int c; cin >> c;
        g.add_edge(a, b, c);
        g.add_edge(b, a, c);
    }

    int diameter = g.tree_diameter();
    cout << diameter << endl;

    return 0;
}
