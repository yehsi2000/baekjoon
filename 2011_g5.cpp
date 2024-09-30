#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string input;
    const int MOD = 1000000;
    cin>>input;
    if(input[0]=='0'){
        cout<<0;
        return 0;   
    }
    int n = input.length();
    vector<int> intinput(n+1,0);
    for(int i=1; i<=n; ++i){
        intinput[i] = input[i-1]-'0';
    }
    vector<int> dp(n+1,0);
    dp[0] = 1;
    for(int i=1; i<=n; ++i){
        if(intinput[i]>0){
            dp[i] = dp[i-1];
        } 
        if(intinput[i-1]==1 || (intinput[i-1]==2 && intinput[i]<7)){
            dp[i] = dp[i] % MOD + dp[i-2] % MOD;
            dp[i] %= MOD;
        }
    }
    cout<<dp[n];
}