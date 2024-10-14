#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long dp[101][101][101];
const long long MOD = 1000000007;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("E:\\dev\\cpptest\\baekjoon\\input.txt", "r", stdin);
  int n, l, r;
  cin >> n >> l >> r;
  dp[1][1][1] = 1;
  
  for (int tot = 2; tot <= n; ++tot) {
    for (int lcnt = 1; lcnt <= n; ++lcnt) {
      for (int rcnt = 1; rcnt <= n; ++rcnt) {
        dp[tot][lcnt][rcnt] =
            (dp[tot - 1][lcnt - 1][rcnt] % MOD) //add smallest on leftest
            + (dp[tot - 1][lcnt][rcnt - 1] % MOD) //add smallest on the rightest
            + ((dp[tot - 1][lcnt][rcnt] * (tot - 2)) % MOD) ; //add smallest in the middle
        dp[tot][lcnt][rcnt]%=MOD;
      }
    }
  }
  cout<< dp[n][l][r];
}