#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D"
#define ERROR "1e-8"
#include <bits/stdc++.h>
#include "../../../lib/geometry/utils.hpp"
using namespace std;

int main() {
    cout << std::fixed << std::setprecision(10);
    using P = complex<double>;

    auto read_p = []()->P {
        int x,y; cin >> x >> y;
        return P(x, y);
    };

    int Q; cin >> Q;
    vector<double> ans(Q);
    const double eps = 1e-8;
    for(int i = 0; i < Q; ++i) {
        P p0 = read_p(), p1 = read_p(), p2 = read_p(), p3 = read_p();
        ans[i] = lib::geometry::distance_l2l(p0, p1, p2, p3, eps);
    }

    for(int i = 0; i < Q; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}

