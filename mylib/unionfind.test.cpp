#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <bits/stdc++.h>
#include "unionfind.hpp"
using namespace std;

int main() {
    int N,Q; cin >> N >> Q;

    mylib::unionfind uf(N);

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
