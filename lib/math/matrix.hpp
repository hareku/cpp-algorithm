#ifndef LIB_MATH_MATRIX_HPP
#define LIB_MATH_MATRIX_HPP 1

#include <bits/stdc++.h>

namespace lib::math {

template <class T> struct matrix {
  public:
    std::vector<std::vector<T>> M;

    matrix() {}
    matrix(int n, int m) : M(n, std::vector<T>(m, 0)) {}
    matrix(int n) : M(n, std::vector<T>(n, 0)) {};

    int height() const {
        return (int) M.size();
    }

    int width() const {
        return (int) M[0].size();
    }

    inline const std::vector<T> &operator[](int k) const {
        return (M.at(k));
    }

    inline std::vector<T> &operator[](int k) {
        return (M.at(k));
    }

    static matrix I(int n) {
        matrix mat(n);
        for(int i = 0; i < n; i++) mat[i][i] = 1;
        return (mat);
    }

    matrix &operator+=(const matrix &B) {
        int n = height(), m = width();
        assert(n == B.height() && m == B.width());
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                (*this)[i][j] += B[i][j];
        return (*this);
    }

    matrix &operator-=(const matrix &B) {
        int n = height(), m = width();
        assert(n == B.height() && m == B.width());
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                (*this)[i][j] -= B[i][j];
        return (*this);
    }

    matrix &operator*=(const matrix &B) {
        int n = height(), m = B.width(), p = width();
        assert(p == B.height());
        std::vector< std::vector<T> > C(n, std::vector<T>(m, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                for(int k = 0; k < p; k++)
                    C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
        M.swap(C);
        return (*this);
    }

    matrix &operator^=(long long k) {
        matrix B = matrix::I(height());
        while(k > 0) {
            if(k & 1) B *= *this;
            *this *= *this;
            k >>= 1LL;
        }
        M.swap(B.M);
        return (*this);
    }

    matrix operator+(const matrix &B) const {
        return (matrix(*this) += B);
    }

    matrix operator-(const matrix &B) const {
        return (matrix(*this) -= B);
    }

    matrix operator*(const matrix &B) const {
        return (matrix(*this) *= B);
    }

    matrix operator^(const long long k) const {
        return (matrix(*this) ^= k);
    }
};

}    // namespace lib::math

#endif    // LIB_MATH_MATRIX_HPP
