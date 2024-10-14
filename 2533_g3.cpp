#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dp[1000001][2];
bool visited[1000001];
vector<vector<int>> link;

void dpchild(int idx) {
  visited[idx] = true;
  dp[idx][1] = 1;
  for (int i = 0; i < link[idx].size(); ++i) {
    int e = link[idx][i];
    if (visited[e]) continue;
    dpchild(e);
    dp[idx][0] += dp[e][1];                 // non-adapter, all friends must be adapter
    dp[idx][1] += min(dp[e][0], dp[e][1]);  // adapter, friends could be adapter or non-adapter
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int n;
  cin>>n;
  link = vector<vector<int>>(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    link[u].push_back(v);
    link[v].push_back(u);
  }
  dpchild(1);
  cout << min(dp[1][0], dp[1][1]);
}