#include <algorithm>
#include <iostream>
#include <vector>
#define INF 1e8

using namespace std;

int n;
int weight[16][16];
int dp[16][1 << 16];

int tsp(int cur, int visited) {
  if (visited == (1 << n) - 1)
    return weight[cur][0] ? weight[cur][0] : INF;
  if (dp[cur][visited])
    return dp[cur][visited];
  dp[cur][visited] = INF;
  for (int i = 0; i < n; ++i) {
    if ((visited & (1 << i)) == 0 && weight[cur][i]) {
      dp[cur][visited] =
          min(dp[cur][visited], tsp(i, visited | (1 << i)) + weight[cur][i]);
    }
  }
  return dp[cur][visited];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);

  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> weight[i][j];
    }
  }
  cout << tsp(0, 1);
}