#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<bool> prime_number_flags(long long n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for(int i = 2; i <= n; ++i) {
        if(!isPrime[i]) continue;

        isPrime[i] = true;

        for(int j = i * 2; j <= n; j += i) {
            isPrime[j] = false;
        }
    }

    return isPrime;
}

template<typename T> map<T, int> prime_factorize(T N) {
    map<T, int> res;
    for (T a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        T ex = 0;

        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        res[a] = ex;
    }

    if (N != 1) res[N] = 1;
    return res;
}
