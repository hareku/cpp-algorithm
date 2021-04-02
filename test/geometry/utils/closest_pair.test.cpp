#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A"
#define ERROR "1e-7"
#include <bits/stdc++.h>
#include "../../../lib/geometry/utils.hpp"
using namespace std;

int main() {
    cout << std::fixed << std::setprecision(10);
    using P = complex<double>;

    int N; cin >> N;
    vector<P> points(N);
    for(int i = 0; i < N; ++i) {
        double x, y; cin >> x >> y;
        points[i] = P(x, y);
    }

    double distance = lib::geometry::closest_pair(points);
    cout << distance << endl;

    return 0;
}
