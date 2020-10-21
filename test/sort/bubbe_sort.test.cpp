#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_A"
#include <bits/stdc++.h>
#include "../../lib/sort/bubble_sort.hpp"
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];

    int swap_count = lib::sort::bubble_sort(A);

    for(int i = 0; i < N; ++i) {
        cout << A[i];
        if(i == N - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }

    cout << swap_count << endl;

    return 0;
}
