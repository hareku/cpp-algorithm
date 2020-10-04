#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"
#include <bits/stdc++.h>
#include "../../lib/sequence/fenwick_tree.hpp"
using namespace std;

int main() {
    int N,Q; cin >> N >> Q;

    lib::sequence::fenwick_tree<int> fenwick(N);

    for(int i = 0; i < Q; ++i) {
        int t; cin >> t;
        int x,y; cin >> x >> y;
        if(t == 0) {
            fenwick.add(x - 1, y);
        } else {
            int res = fenwick.sum(x - 1, y);
            cout << res << endl;
        }
    }

    return 0;
}
