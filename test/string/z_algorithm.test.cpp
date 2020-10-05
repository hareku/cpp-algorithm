#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include <bits/stdc++.h>
#include "../../lib/string/z_algorithm.hpp"
using namespace std;

int main() {
    string S; cin >> S;

    auto lcs = lib::string::z_algorithm(S);
    int n = int(lcs.size());
    for(int i = 0; i < n; ++i) {
        cout << lcs[i];
        if(i == n - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }

    return 0;
}
