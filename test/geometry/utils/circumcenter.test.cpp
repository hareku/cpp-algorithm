#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_C"
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

    P a = read_p(), b = read_p(), c = read_p();
    P circumcenter = lib::geometry::circumcenter(a, b, c);
    double radius = abs(a - circumcenter);

    cout << circumcenter.real() << " " << circumcenter.imag() << " " << radius << endl;

    return 0;
}
