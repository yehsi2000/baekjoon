#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int list[1000000];
    int dp[1000000]={0,};
    int n, res = 0;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>list[i];
        for(int j=0; j<i; ++j){
            if(list[i]>list[j] && dp[i]<=dp[j]){
                dp[i] = dp[j] + 1;
            }
        }
        if(res<dp[i]) res = dp[i];
    }
    cout<<res+1;

}