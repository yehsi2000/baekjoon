#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[1001][1001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int n, m, maxsize{};
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    string tmp;
    cin >> tmp;
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = tmp[j - 1] - '0';
      if (dp[i][j]) {
        dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
        maxsize = max(maxsize, dp[i][j]);
      }
    }
  }
  cout << maxsize * maxsize;
}