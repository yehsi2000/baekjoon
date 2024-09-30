#include <cstdio>
#include <algorithm>
using namespace std;
int packs[1001];
int dp[1001];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        scanf("%d",packs+i);
    }
    dp[1] = packs[1];
    for(int i=2; i<=n; ++i){
        dp[i] = packs[i];
        for(int j=1; j<=i/2; ++j){
            dp[i] = max(dp[i],dp[i-j]+dp[j]);
        }
    }

    printf("%d", dp[n]);
}