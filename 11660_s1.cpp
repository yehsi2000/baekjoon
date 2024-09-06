#include <cstdio>

int dp[1025][1025];

int main(){
    int n, m;
    scanf("%d %d",&n, &m);
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            scanf("%d", &dp[i][j]);
            dp[i][j] += dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1];
        }
    }
    for(int i=0; i<m; ++i){
        int xb,yb,xe,ye;
        scanf("%d %d %d %d", &xb, &yb, &xe, &ye);
        int sum = dp[xe][ye] - dp[xb-1][ye] - dp[xe][yb-1] + dp[xb-1][yb-1];
        printf("%d\n", sum);
    }
    return 0;
}