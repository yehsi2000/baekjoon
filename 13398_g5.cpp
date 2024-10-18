#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int n;
  cin>>n;
  int dp[2][2]={};
  int num, maxsum = 0;
  for(int i=0; i<n; ++i){
    cin>>num;
    if(i==0) {
      dp[i%2][0] = num;
      maxsum = dp[i%2][0];
    }
    else {
      dp[i%2][0] = max(0,dp[(i+1)%2][0]) + num;
      maxsum = max(maxsum ,dp[i%2][0]);
      dp[i%2][1] = max(dp[(i+1)%2][0], dp[(i+1)%2][1] + num);
      maxsum = max(maxsum ,dp[i%2][1]);
    }

  }
  cout<<maxsum;

  
}