#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, res=0;
    scanf("%d", &n);
    vector<int> list(n);
    vector<int> dp(n,0);
    for(int i=0; i<n; ++i){
        scanf("%d",&list[i]);
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<i; ++j){
            if(list[i]<list[j] && dp[i]<=dp[j]){
                dp[i] = dp[j] + 1;
            }
        }
        res=max(res,dp[i]);
    }

    printf("%d", res+1);
}