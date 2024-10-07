#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int n, k;
  cin >> n >> k;
  vector<int> values(n);
  vector<int> dp(k+1,100001);
  dp[0] = 0;
  for (int i = 0; i < n; ++i)
    cin >> values[i];

  for(int i=1; i<=k; ++i){
    for(int j=0; j<n; ++j){
      if(values[j]<=i)
        dp[i] = min(dp[i],dp[i-values[j]]+1);
    }
  }
  if (dp[k] == 100001)
    cout << -1;
  else
    cout << dp[k];
}