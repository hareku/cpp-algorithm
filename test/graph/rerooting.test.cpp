#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595"
#include <bits/stdc++.h>
#include "../../lib/graph/rerooting.hpp"
using namespace std;

int operate(int a, int b) {
    return max(a,b);
}
int operateNode(int a, int node) {
    return a+1;
}

int main() {
    int N; cin >> N;
    vector<vector<int>> edges;

    for(int i = 0; i < N-1; ++i) {
        int u,v;
        cin >> u >> v;
        --u, --v;
        edges.push_back(vector<int>({u, v}));
    }

    lib::graph::ReRooting<int> G(N, edges, 0, operate, operateNode);

    for(int i = 0; i < N; ++i) {
        auto farthest = G.Query(i);
        int ans = N*2 - farthest - 1;
        cout << ans << endl;
    }
}
