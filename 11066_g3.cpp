#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dp[501][501];
int sum[501];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    //vector<vector<int>> dp(n, vector<int>(n));
    //vector<int> sum(n + 1);
    for (int i = 0; i < n; ++i) {
      int tmp;
      cin>>tmp;
      sum[i + 1] = sum[i] + tmp;
    }
    for (int size = 1; size < n; ++size) {
      for (int start = 0; start + size < n; ++start) {
        dp[start][start + size] = 250 * (20000 + 500 * 10000);
        for (int mid = start; mid < start + size; ++mid) {
          int cursum = dp[start][mid] + dp[mid + 1][start + size];
          cursum += sum[start + size + 1] - sum[start];
          dp[start][start + size] = min(dp[start][start + size], cursum);
        }
      }
    }
    cout << dp[0][n - 1] << "\n";
  }
}