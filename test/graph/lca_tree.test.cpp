#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include <bits/stdc++.h>
#include "../../lib/graph/lca_tree.hpp"
using namespace std;

int main() {
    int N,Q; cin >> N >> Q;
    lib::graph::lca_tree tree(N);

    for(int i = 1; i < N; ++i) {
        int p; cin >> p;
        tree.add_edge(p, i);
    }

    tree.build();
    for(int i = 0; i < Q; ++i) {
        int a,b; cin >> a >> b;
        cout << tree.lca(a, b) << endl;
    }
    return 0;
}
