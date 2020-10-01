#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

// https://ja.wikipedia.org/wiki/%E9%81%B8%E6%8A%9E%E3%82%BD%E3%83%BC%E3%83%88
int main() {
  int N;
  cin >> N;
  int A[N];
  rep(i, N) cin >> A[i];

  for(int i = 0; i < N - 1; i++) {
    int m = i;
    for(int j = i + 1; j < N; j++) {
      if(A[m] > A[j]) {
        m = j;
      }
    }
    swap(A[i], A[m]);
  }

  rep(i, N) cout << A[i] << " ";
  cout << endl;
}
