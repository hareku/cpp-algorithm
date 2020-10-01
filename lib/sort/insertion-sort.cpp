#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

// https://ja.wikipedia.org/wiki/%E6%8C%BF%E5%85%A5%E3%82%BD%E3%83%BC%E3%83%88
int main() {
  int N;
  cin >> N;
  int A[N];
  rep(i, N) cin >> A[i];

  for(int i = 1; i <= N; i++) {
    int v = A[i];
    int j = i - 1;
    while(j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
  }

  rep(i, N) cout << A[i] << " ";
  cout << endl;
}
