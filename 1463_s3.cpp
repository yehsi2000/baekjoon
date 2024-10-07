#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dp[1000001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;

  for (int i = 2; i <= n; ++i) {
    int a = 1000001, b = 1000001;
    if (i % 3 == 0)
      a = dp[i / 3] + 1;
    if (i % 2 == 0)
      b = dp[i / 2] + 1;
    dp[i] = min(min(a, b), dp[i - 1] + 1);
  }
  cout << dp[n] << "\n";
  vector<int> trace;
  trace.push_back(n);
  while (n > 1) {
    int a = 1000001, b = 1000001;
    if (n % 3 == 0) a = dp[n / 3];
    if (n % 2 == 0) b = dp[n / 2];
    if (a < dp[n - 1]) {
      if (a < b) n /= 3;
      else n /= 2;
    } else {
      if (b < dp[n - 1]) n /= 2;
      else n--;
    }
    trace.push_back(n);
  }
  for (int i = 0; i < trace.size(); ++i) {
    cout << trace[i] << " ";
  }
}