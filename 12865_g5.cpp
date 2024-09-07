#include <cstdio>
#define MAX(x,y) (x)>(y)?(x):(y)

int main(){
    int n,k,w,v;
    scanf("%d %d", &n, &k);
    int dp[k+1] = {0,};
    for(int i=1; i<=n; ++i){
        scanf("%d %d", &w, &v);
        for(int j=k; j>=w; --j){
            dp[j] = MAX(dp[j-w]+v,dp[j]);
        }
    }
    printf("%d", dp[k]);
    
}