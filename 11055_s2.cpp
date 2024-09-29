#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int> list;
    while(n--){
        int tmp;
        cin>>tmp;
        list.push_back(tmp);
    };
    vector<int> dp = list;
    int maxsum = 0;
    for(int i=0; i<list.size(); ++i){
        for(int j=0; j<i; ++j){
            if(list[j]<list[i] && dp[i]<dp[j]+list[i]){
                dp[i] = dp[j] + list[i];
            }
        }
        maxsum = max(dp[i],maxsum);
    }
    cout<<maxsum;

}