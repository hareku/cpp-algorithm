#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C"
#include <bits/stdc++.h>
#include "../../lib/sequence/lcs.hpp"
using namespace std;

int main() {
    int N; cin >> N;
    for(int i = 0; i < N; ++i) {
        string a,b; cin >> a >> b;
        vector<char> av(a.begin(), a.end()), bv(b.begin(), b.end());

        int ans = lib::sequence::lcs(av, bv);
        cout << ans << endl;
    }

    return 0;
}
