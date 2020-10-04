#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0167"
#include <bits/stdc++.h>
#include "../../lib/sort/bubble_sort.hpp"
using namespace std;

int main() {
    int N;
    while(cin >> N, N) {
        vector<int> A(N);
        for(int i = 0; i < N; ++i) cin >> A[i];

        int res = lib::sort::bubble_sort(A);
        cout << res << endl;
    }

    return 0;
}
