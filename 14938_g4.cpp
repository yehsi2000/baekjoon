#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m, r;

void FloydWarshall(vector<vector<int>> &dist) {
  for (int m = 1; m <= n; ++m)
    for (int s = 1; s <= n; ++s)
      for (int e = 1; e <= n; ++e) dist[s][e] = min(dist[s][e], dist[s][m] + dist[m][e]);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  cin >> n >> m >> r;
  vector<int> areaitem(n+1);
  vector<vector<int>> dist(n+1, vector<int>(n+1, 1501));
  for (int i = 1; i <= n; ++i){
    cin >> areaitem[i];
    dist[i][i] = 0;
  }
  
  int a, b, w;
  for (int i = 0; i < r; ++i) {
    cin >> a >> b >> w;
    dist[a][b] = w;
    dist[b][a] = w;
  }
  FloydWarshall(dist);
  int maxitem{};
  for(int firstdrop=1; firstdrop<n; ++firstdrop){
    int curitem{};
    for(int area=1; area<=n; ++area){
      if(dist[firstdrop][area] <= m){
        curitem += areaitem[area];
      }
    }
    maxitem = max(maxitem, curitem);
  }
  cout<<maxitem;
}