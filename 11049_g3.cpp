#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int n;
  cin >> n;
  vector<pair<int, int>> mat(n);
  vector<vector<int>> dp(n, vector<int>(n, ~(1 << 31)));
  for (int i = 0; i < n; ++i) {
    dp[i][i] = 0;
    cin >> mat[i].first >> mat[i].second;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j + i < n; ++j) {
      for (int k = j; k < j + i; ++k) {
        dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][j + i] +
                                             mat[j].first * mat[k].second *
                                                 mat[i + j].second);
      }
    }
  }
  cout << dp[0][n - 1];
}