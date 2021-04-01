#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A"
#include <bits/stdc++.h>
#include "../../../lib/geometry/utils.hpp"
using namespace std;

int main() {
    cout << std::fixed << std::setprecision(1);
    using P = complex<double>;

    int N; cin >> N;

    auto read_p = []()->P {
        int x,y; cin >> x >> y;
        return P(x, y);
    };

    vector<P> points(N);

    for(int i = 0; i < N; ++i) {
        points[i] = read_p();
    }

    double area = lib::geometry::area(points);

    cout << area << endl;

    return 0;
}
