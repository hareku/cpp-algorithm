#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"
#include <bits/stdc++.h>
#include "maxflow.hpp"
using namespace std;

int main() {
    int V,E; cin >> V >> E;

    mylib::maxflow_graph<int> g(V);

    for(int i = 0; i < E; ++i) {
        int u,v,c; cin >> u >> v >> c;
        g.add_edge(u, v, c);
    }

    int maxflow = g.flow(0, V - 1);
    cout << maxflow << endl;

    return 0;
}
