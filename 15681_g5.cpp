#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> links[100001];
int childs[100001];

int dfs(int idx, int parent) {
  int ret = 0;
  if (links[idx].size()>0) {
    for (int e : links[idx]){
      if(e==parent) continue;
      ret += dfs(e,idx);
    }
    childs[idx] = ret;
  }

  return ret+1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int n, r, q;
  cin >> n >> r >> q;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    links[u].push_back(v);
    links[v].push_back(u);
  }
  dfs(r,0);
  for (int i = 0; i < q; ++i) {
    int query;
    cin >> query;
    cout << childs[query]+1 << "\n";
  }
}