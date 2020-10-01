#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include <bits/stdc++.h>
#include "bipartite_matching.hpp"
using namespace std;

int main() {
    int L,R,M; cin >> L >> R >> M;

    mylib::bipartite_matching_graph g(L, R);

    for(int i = 0; i < M; ++i) {
        int a,b; cin >> a >> b;
        g.add_edge(a, b);
    }

    int maxflow = g.bipartite_matching();
    cout << maxflow << endl;

    auto matches = g.matches();
    for(auto& m : matches) {
        cout << m.first << " " << m.second << endl;
    }

    return 0;
}
