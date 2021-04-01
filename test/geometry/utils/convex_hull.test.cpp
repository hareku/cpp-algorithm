#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"
#include <bits/stdc++.h>
#include "../../../lib/geometry/utils.hpp"
using namespace std;

int main() {
    using P = complex<int>;

    int N; cin >> N;
    vector<P> points(N);

    for(int i = 0; i < N; ++i) {
        int x,y; cin >> x >> y;
        points[i] = P(x, y);
    }

    auto convex = lib::geometry::convex_hull(points);
    int k = (int) convex.size();
    cout << k << endl;

    for(int i = 0; i < k; ++i) {
        cout << convex[i].real() << " " << convex[i].imag() << endl;
    }

    return 0;
}
