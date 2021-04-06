#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_6_A"
#include <bits/stdc++.h>
#include "../../lib/geometry/intersections.hpp"
using namespace std;

int main() {
    using P = complex<int>;
    using L = pair<P, P>;
    auto read_p = []()->P {
        int x,y; cin >> x >> y;
        return P(x, y);
    };

    int N; cin >> N;
    vector<L> lines(N);
    for(int i = 0; i < N; ++i) {
        lines[i] = L(read_p(), read_p());
    }

    cout << lib::geometry::count_intersections(lines) << endl;

    return 0;
}
