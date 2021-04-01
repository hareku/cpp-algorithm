#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B"
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
    vector<bool> ans(Q);
    for(int i = 0; i < Q; ++i) {
        P p0 = read_p(), p1 = read_p(), p2 = read_p(), p3 = read_p();
        ans[i] = lib::geometry::is_intersected(p0, p1, p2, p3);
    }

    for(int i = 0; i < Q; ++i) {
        if(ans[i]) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}
