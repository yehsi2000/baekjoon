#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int n, w;
pair<int, int> casepos[1010];
int to[1010];
int dp[1010];
bool ans[1010];

int dist(int a, int b) {
  if (b == w + 2) return 0;
  auto& [c, d] = casepos[a];
  auto& [e, f] = casepos[b];
  return abs(c - e) + abs(d - f);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  cin >> n >> w;
  casepos[0] = {1, 1};
  casepos[1] = {n, n};
  for (int i = 2; i < w + 2; ++i) {
    auto& [a, b] = casepos[i];
    cin >> a >> b;
  }
  for (int i = w - 1; i >= 0; --i) {
    dp[i] = INF;
    for (int sum = 0, j = i + 1; j < w + 2; sum += dist(j, j + 1), ++j) {
      int tmp = dp[j] + sum + dist(i, j + 1);
      if (dp[i] > tmp) {
        dp[i] = tmp;
        to[i] = j;
      }
    }
  }
  to[w] = to[w + 1] = w + 2;
  for (int i = 0, car = 1; i <= w + 1; i = to[i], car ^= 1) {
    for (int j = i + 1; j <= to[i]; ++j) {
      ans[j] = car;
    }
  }
  cout << dp[0] << '\n';
  for (int i = 2; i < w + 2; ++i) {
    cout << ans[i] + 1 << '\n';
  }
}