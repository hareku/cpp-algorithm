#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"
#include <bits/stdc++.h>
#include "../../../lib/geometry/utils.hpp"
using namespace std;

int main() {
    cout << std::fixed << std::setprecision(10);
    using P = complex<long double>;

    int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
    P p0 = P(x1, y1), p1 = P(x2, y2);

    int Q; cin >> Q;
    vector<int> ans(Q);
    for(int i = 0; i < Q; ++i) {
        int x,y; cin >> x >> y;
        P p2 = P(x, y);
        ans[i] = lib::geometry::ccw(p0, p1, p2);
    }

    for(int i = 0; i < Q; ++i) {
        if(ans[i] == 1) {
            cout << "COUNTER_CLOCKWISE" << endl;
        } else if(ans[i] == -1) {
            cout << "CLOCKWISE" << endl;
        } else if(ans[i] == 2) {
            cout << "ONLINE_BACK" << endl;
        } else if(ans[i] == -2) {
            cout << "ONLINE_FRONT" << endl;
        } else if(ans[i] == 0) {
            cout << "ON_SEGMENT" << endl;
        }
    }

    return 0;
}
