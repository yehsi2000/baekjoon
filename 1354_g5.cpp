#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;

unordered_map<long long, long long> dp;
long long n, p, q, x, y;

long long calc(long long idx) {
  if (idx <= 0) return 1;
  if (dp.find(idx) != dp.end()) {
    return dp[idx];
  }
  return dp[idx] = (idx / p > x ? calc(idx / p - x) : 1) + (idx / q > y ? calc(idx / q - y) : 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);

  cin >> n >> p >> q >> x >> y;
  cout << calc(n);
}