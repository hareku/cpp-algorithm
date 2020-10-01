#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

// https://ja.wikipedia.org/wiki/%E3%83%90%E3%83%96%E3%83%AB%E3%82%BD%E3%83%BC%E3%83%88
int main() {
  int N;
  cin >> N;
  int A[N];
  rep(i, N) cin >> A[i];

  for(int i = 0; i < N - 1; i++) {
    for(int j = N - 1; j > i; j--) {
      if(A[j - 1] > A[j]) {
        swap(A[j], A[j - 1]);
      }
    }
  }

  rep(i, N) cout << A[i] << " ";
  cout << endl;
}
