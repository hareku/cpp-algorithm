#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_A"
#include <bits/stdc++.h>
#include "../../lib/sort/insertion_sort.hpp"
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];

    auto res = lib::sort::insertion_sort(A);

    for(auto& a : res) {
        for(int i = 0; i < N; ++i) {
            cout << a[i];
            if(i == N - 1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }

    return 0;
}
