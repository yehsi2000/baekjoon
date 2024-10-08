#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1e8

int weight[16][16];
int dp[16][1<<16];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int n;
  int val;
  cin>>n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cin>> weight[i][j];
    for (int j = 0; j < (1<<n); j++)
      dp[i][j] = INF;
  }
  dp[0][1] = 0;
  for (int visited = 1; visited < (1<<n); visited++) {
    if (!(visited & 1)) //0에서 시작 0방문안한것 스킵
      continue;
    for (int i = 1; (1 << i) < visited; i++) {
      //i번째 방문 안했거나 i번째만 방문했을 경우 스킵
      if (!(visited & (1 << i)) || !(visited - (1 << i)))
        continue;
      //i번째 방문안한 비트맵
      int bit = visited ^ (1 << i);

      dp[i][visited] = INF;
      for (int j = 0; j < n; j++) {
        //j에서 i로 갈수있는 애들만
        if (!weight[j][i])
          continue;
        //j에서 i번째 방문안했을때 j에서 i로 가는거
        dp[i][visited] = min(dp[i][visited], dp[j][bit] + weight[j][i]);
      }
      
    }
  }
  int min_weight = INF;
  for (int i = 0; i < n; i++) {
    if (!weight[i][0])
      continue;
    val = dp[i][(1<<n)-1] + weight[i][0];
    if (val < min_weight)
      min_weight = val;
  }
  cout<< min_weight;
}