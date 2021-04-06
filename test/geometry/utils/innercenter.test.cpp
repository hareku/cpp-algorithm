#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_B"
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
    P innercenter = lib::geometry::innercenter(a, b, c);
    P prj = lib::geometry::projection(innercenter, a, b);
    double radius = abs(innercenter - prj);

    cout << innercenter.real() << " " << innercenter.imag() << " " << radius << endl;

    return 0;
}
