#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C"
#define ERROR "1e-6"
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

    int N; cin >> N;
    vector<P> polygon(N);
    for(int i = 0; i < N; ++i) {
        polygon[i] = read_p();
    }

    int Q; cin >> Q;
    vector<double> ans(Q);
    for(int i = 0; i < Q; ++i) {
        P a = read_p(), b = read_p();
        vector<P> cut = lib::geometry::cut_convex(polygon, a, b);
        ans[i] = lib::geometry::area(cut);
    }

    for(int i = 0; i < Q; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}
