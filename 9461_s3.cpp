#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    long long dp[101] = {1,1,1,2,2,3,4,5,7,9,0,};
    for(int i=10; i<=100;i++){
        dp[i] = dp[i-5]+dp[i-1];
    }
    while(t--){
        int n;
        cin>>n;
        cout<<dp[n-1]<<"\n";
    }
}