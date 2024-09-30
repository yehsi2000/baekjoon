#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int staircnt;
    cin>>staircnt;
    vector<int> stairs(staircnt);
    for(int i=0; i<staircnt; ++i){
        cin>>stairs[i];
    }
    vector<int> dp(staircnt);
    dp[0] = stairs[0];
    if(staircnt>0) dp[1] = stairs[0]+stairs[1];
    if(staircnt>1) dp[2] = max(stairs[1]+stairs[2],stairs[0]+stairs[2]);
    for(int i=3; i<staircnt; ++i){
        dp[i] = max(stairs[i] + stairs[i-1] + dp[i-3], dp[i-2] + stairs[i]);
    }
    cout<<dp[staircnt-1];

}