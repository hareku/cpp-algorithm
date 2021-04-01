#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B"
#define ERROR "1e-8"
#include <bits/stdc++.h>
#include "../../../lib/geometry/utils.hpp"
using namespace std;

int main() {
    cout << std::fixed << std::setprecision(10);
    using P = complex<double>;

    int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
    P p1 = P(x1, y1), p2 = P(x2, y2);

    int Q; cin >> Q;
    vector<P> ans(Q);
    for(int i = 0; i < Q; ++i) {
        int x,y; cin >> x >> y;
        P p = P(x, y);
        ans[i] = lib::geometry::reflection(p, p1, p2);
    }

    for(int i = 0; i < Q; ++i) {
        cout << ans[i].real() << " " << ans[i].imag() << endl;
    }

    return 0;
}
