#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"
#include <bits/stdc++.h>
#include "../../lib/graph/weighted_unionfind.hpp"
using namespace std;

int main() {
    int N,Q; cin >> N >> Q;

    lib::graph::weighted_unionfind<int> uf(N);

    for(int i = 0; i < Q; ++i) {
        int t; cin >> t;
        if(t == 0) {
            int x,y,z; cin >> x >> y >> z;
            uf.merge(x, y, z);
        } else {
            int x,y; cin >> x >> y;
            if(uf.same(x, y)) {
                cout << uf.diff(x, y) << endl;
            } else {
                cout << '?' << endl;
            }
        }
    }

    return 0;
}
