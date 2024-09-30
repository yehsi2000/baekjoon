#include <iostream>
using namespace std;

int dp[201][201];
const int MOD = 1000000000;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    //dp[k][n]
    for(int i=0; i<=200; ++i){
        dp[i][1] = 1;
        dp[0][i] = 1;
        dp[1][i] = i;
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=k; ++j){
            dp[i][j] = dp[i-1][j] % MOD + dp[i][j-1] % MOD;
            dp[i][j] %= MOD;
        }
    }
    cout<<dp[n][k];
}
