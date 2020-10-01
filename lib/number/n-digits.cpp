#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
using namespace std;

// 数字の先頭の桁と末尾の桁を求める
// https://atcoder.jp/contests/abc152/tasks/abc152_d
pair<int,int> getHeadAndTail(int num) {
    int first = num % 10;

    while(num >= 10) {
        num /= 10;
    }

    return make_pair(num, first);
}

// 桁数を求める
int countDigits(long long num) {
    int cnt = 0;
    while(num) {
        ++cnt;
        num /= 10;
    }
    return cnt;
}

// 10進数numをn進数であらわした時の桁数を求める
// https://atcoder.jp/contests/abc156/tasks/abc156_b
int n_digits(int num, int n) {
    if(num == 0) return 1;

    int ans = 0;
    while(num) {
        ++ans;
        num /= n;
    }
    return ans;
}

// 10進数numをn進数に変換する
// convert_n(1, 2) -> [1, 0, 1, 1]
vector<int> convert_n(int num, int n) {
    vector<int> ans;
    while(num) {
        ans.push_back(num % n);
        num /= n;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// n(<=10)進数numをn2(<=10)進数に変換する
vector<int> convert_n2n(vector<int> nums, int n, int n2) {
    int n10_num = 0;
    int w = 0;
    for(int i = nums.size() - 1; i >= 0; --i) {
        n10_num += (int)pow(n, w++) * nums[i];
    }

    return convert_n(n10_num, 10);
}
