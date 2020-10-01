#include <bits/stdc++.h>
using namespace std;

// 回文かどうかを判定
bool is_palindrome(const string &s){
    int n = s.length();
    for (int i = 0; i < (n+1)/2; ++i) {
        if(s[i] != s[n-i-1]) return false;
    }
    return true;
}

int main() {
  //
}
