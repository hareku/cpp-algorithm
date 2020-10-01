#include <bits/stdc++.h>
using namespace std;
#define MAX 2000000;
int H, A[2000001];

void maxHeapify(int i) {
  int l,r,largest;
  l = 2 * i;
  r = 2 * i + 1;

  if(l <= H && A[l] > A[i]) largest = l;
  else largest = i;
  if(r <= H && A[r] > A[largest]) largest = r;

  if(largest != i) {
    swap(A[i], A[largest]);
    maxHeapify(largest);
  }
}

int pop() {
  if(H < 1) return INT_MIN;
  int maxv = A[1];

  A[1] = A[H--];
  maxHeapify(1);

  return maxv;
}

void increaseKey(int i, int val) {
  A[i] = val;
  while(i > 1 && A[i / 2] < A[i]) {
    swap(A[i], A[i / 2]);
    i /= 2;
  }
}

void insert(int val) {
  H++;
  increaseKey(H, val);
}

// priority queue
// https://ja.wikipedia.org/wiki/%E5%84%AA%E5%85%88%E5%BA%A6%E4%BB%98%E3%81%8D%E3%82%AD%E3%83%A5%E3%83%BC
int main() {
  cout << pop() << endl;
  insert(1), insert(2), insert(3);
  cout << pop() << endl;
  insert(10);
  cout << pop() << endl;
  cout << pop() << endl;
  insert(5), insert(6), insert(7);
  cout << pop() << endl;
  cout << pop() << endl;
}
