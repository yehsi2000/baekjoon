#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool palindp[2501][2501];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  string input;
  cin >> input;
  int n = input.length();
  for (int i = 0; i < n; ++i) palindp[i][i] = true;
  for (int i = 1; i < n; ++i) {
    int j;
    for (j = 1; i - j >= 0 && i + j < n; ++j) {
      if (input[i - j] == input[i + j]) {
        palindp[i - j][i + j] = true;
      } else break;
    }

    if (input[i - 1] == input[i]) {
      palindp[i-1][i] = true;
      for (j = 1; i - j - 1 >= 0 && i + j < n; ++j) {
        if (input[i - j - 1] == input[i + j]) {
          palindp[i - j - 1][i + j] = true;
        } else {
          break;
        }
      }
    }
  }
  int cnt = 0;
  vector<int> dp(n+1);
  for (int i = 1; i <= n; ++i) {
    dp[i] = 5000;
    for(int j=1; j<=i; ++j){
      if(palindp[j-1][i-1])
        dp[i] = min(dp[i],dp[j-1]+1);
    }
  }
  cout<<dp[n];
}