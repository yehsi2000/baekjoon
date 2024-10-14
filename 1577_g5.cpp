#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long dp[102][102];
int broken[102][102];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int n,m,k;
  cin>>n>>m>>k;
  for(int i=0; i<k; ++i){
    int ax,ay,bx,by;
    cin>>ax>>ay>>bx>>by;
    if(ax==bx){
      if(ay < by){
        broken[bx][by] |= 2;
      } else {
        broken[ax][ay] |= 2;
      }
    } else if(ay==by) {
      if(ax<bx){
        broken[bx][by] |= 1;
      } else {
        broken[ax][ay] |= 1;
      }
    }
  }
  dp[0][0]=1;
  for(int i=0; i<=n; ++i){
    for(int j=0; j<=m; ++j){
      if(i==0 && j==0) continue;
      if((broken[i][j] & 1) ==0 && i>0){
        dp[i][j] += dp[(i-1)][j];
      }
      if((broken[i][j] & 2) ==0 && j>0){
        dp[i][j] +=dp[i][j-1];
      }
    }
  }
  cout<<dp[n][m];
}