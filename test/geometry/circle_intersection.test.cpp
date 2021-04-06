#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A"
#define ERROR "1e-6"
#include <bits/stdc++.h>
#include "../../lib/geometry/circle_intersection.hpp"
using namespace std;

int main() {
    using P = complex<double>;
    auto read_p = []()->P {
        int x,y; cin >> x >> y;
        return P(x, y);
    };

    P a = read_p();
    double ar; cin >> ar;
    P b = read_p();
    double br; cin >> br;

    if(lib::geometry::circles_circumscribed(a, ar, b, br)) {
        cout << 3 << endl;
    } else if(lib::geometry::circles_inscribed(a, ar, b, br)) {
        cout << 1 << endl;
    } else if(lib::geometry::circle_includes(a, ar, b, br)) {
        cout << 0 << endl;
    } else if(lib::geometry::circles_cross(a, ar, b, br)) {
        cout << 2 << endl;
    } else {
        cout << 4 << endl;
    }

    return 0;
}
