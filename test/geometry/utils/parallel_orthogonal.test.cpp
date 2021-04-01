#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A"
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
    vector<int> ans(Q);
    for(int i = 0; i < Q; ++i) {
        P p0 = read_p(), p1 = read_p(), p2 = read_p(), p3 = read_p();

        if(lib::geometry::is_parallel(p0, p1, p2, p3)) {
            ans[i] = 2;
        } else if(lib::geometry::is_orthogonal(p0, p1, p2, p3)) {
            ans[i] = 1;
        } else {
            ans[i] = 0;
        }
    }

    for(int i = 0; i < Q; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}
