#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <array>
#define INF 987654321;
using namespace std;

int dp[100005][5][5];

int step (int now, int move){
  if(now==0)
    return 2;
  if(now==move)
    return 1;
  if(abs(move-now)==2)
    return 4;
  else
    return 3;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int lefthp, righthp;
  int curnote{};
  int time=1;

  for(int i=0; i<=4; ++i){
    for(int j=0; j<=4; ++j){
      dp[0][i][j] = INF;
    }
  }
  dp[0][0][0] = 0;
  
  while(1){
    cin>>curnote;
    if(curnote==0) break;
  
    for(int i=0; i<=4; ++i){
      for(int j=0; j<=4; ++j){
        dp[time][i][j] = INF;
      }
    }
    for(int i=0; i<=4; ++i){
      for(int j=0; j<=4; ++j){
        //leftstepping with right foot on i = prevstep right and left on i, prevstep left and rightfoot on i
        if(curnote!=j) dp[time][curnote][j] = min(dp[time][curnote][j], dp[time-1][i][j] + step(i, curnote));
        //right stepping with left foot on i = prevstep left and right on j, prevstep right and left foot on i
        if(curnote!=i) dp[time][i][curnote] = min(dp[time][i][curnote], dp[time-1][i][j] + step(j, curnote));
      }
    } 
    time++;
  }
  int minhp = INF;
  for(int i=0; i<=4; ++i){
    for(int j=0; j<=4; ++j){
      minhp = min(minhp,dp[time-1][i][j]);
    }
  }
  cout<<minhp;
  
}