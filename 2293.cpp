//동전 1 골5
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> coins;
int dp[100001]={1,};

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    coins.reserve(n);
    int input;
    for(int i=0;i<n;++i){
        scanf("%d",&input);
        coins.push_back(input);
    }
    sort(coins.begin(),coins.end());
    for(int coin : coins)
        for(int i=coin;i<=k;++i)
            dp[i]=dp[i-coin]+dp[i];
    
    printf("%d",dp[k]);
    return 0;
}
