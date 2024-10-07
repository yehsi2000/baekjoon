#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dp[5001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin>>n;
  dp[3]=1;
  dp[5]=1;
  for(int i=6; i<=n; ++i){
    if(dp[i-3] && dp[i-5]) dp[i]=min(dp[i-3],dp[i-5])+1;
    else if(dp[i-3]) dp[i] = dp[i-3] + 1;
    else if(dp[i-5]) dp[i] = dp[i-5] + 1;
  }
  if(dp[n]) cout<<dp[n];
  else cout<<-1;

}