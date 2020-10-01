#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <bits/stdc++.h>
#include "../../lib/graph/unionfind.hpp"
using namespace std;

int main() {
    int N,Q; cin >> N >> Q;

    lib::graph::unionfind uf(N);

    for(int i = 0; i < Q; ++i) {
        int t; cin >> t;
        if(t == 0) {
            int u,v; cin >> u >> v;
            uf.merge(u, v);
        } else {
            int u,v; cin >> u >> v;
            cout << uf.same(u, v) << endl;
        }
    }
}
