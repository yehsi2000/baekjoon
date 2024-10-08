#include <algorithm>
#include <iostream>

using namespace std;

int bamboo[500][500];
int dp[500][500];
int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, 1, -1};
int n;
int dfs(int r, int c) {
  if (dp[r][c])
    return dp[r][c];

  dp[r][c] = 1;

  for (int i = 0; i < 4; ++i) {
    int nr = r + dirx[i];
    int nc = c + diry[i];
    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
        bamboo[r][c] < bamboo[nr][nc]) {
      dp[r][c] = max(dp[r][c], dfs(nr, nc) + 1);
    }
  }
  return dp[r][c];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int maxcnt{};
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> bamboo[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      maxcnt = max(maxcnt, dfs(i, j));
    }
  }
  cout << maxcnt;
  return 0;
}