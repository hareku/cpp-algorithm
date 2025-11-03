#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_A"
#include <bits/stdc++.h>
#include "../../lib/string/kmp.hpp"
using namespace std;

int main() {
    string T,P; cin >> T >> P;

    auto result = lib::string::kmp_search(T,P);
    for(auto r:result) {
        cout << r << endl;
    }

    return 0;
}
