#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        int m;
        scanf(" %d", &m);
        vector<int> list[2];
        list[0].reserve(m);
        list[1].reserve(m);
        for(int j=0; j<m; ++j) scanf("%d", &list[0][j]);
        for(int j=0; j<m; ++j) scanf("%d", &list[1][j]);
        int dp[100001][3] = {0,};
        dp[0][0] = 0; //not picking on this line
        dp[0][1] = list[0][0]; //picking upper one
        dp[0][2] = list[1][0]; //picking lower one
        for(int j=1; j<m; ++j){
            dp[j][0] = max(dp[j-1][1],dp[j-1][2]);
            dp[j][1] = max(dp[j-1][0],dp[j-1][2]) + list[0][j];
            dp[j][2] = max(dp[j-1][0],dp[j-1][1]) + list[1][j];
        }
        printf("%d\n",max(max(dp[m-1][0],dp[m-1][1]),dp[m-1][2]));
    }
    return 0;
}