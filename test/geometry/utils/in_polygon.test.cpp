#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C"
#include <bits/stdc++.h>
#include "../../../lib/geometry/utils.hpp"
using namespace std;

int main() {
    cout << std::fixed << std::setprecision(1);
    using P = complex<double>;

    auto read_p = []()->P {
        int x,y; cin >> x >> y;
        return P(x, y);
    };

    int N; cin >> N;
    vector<P> points(N);
    for(int i = 0; i < N; ++i) {
        points[i] = read_p();
    }

    int Q; cin >> Q;
    vector<int> ans(Q);
    for(int i = 0; i < Q; ++i) {
        P p = read_p();
        ans[i] = lib::geometry::in_polygon(p, points);
    }

    for(int i = 0; i < Q; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}
