#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool dp[2001][2001] = {false,};
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("E:\\dev\\cpptest\\baekjoon\\input.txt","r",stdin);
    int n,m, start, end;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; ++i) {
        cin>>nums[i];
        dp[i][i] = true;
    }
    for(int i=1; i<n; ++i){
        for(int j = 1; i-j>=0 && i+j<n; ++j){
            if(nums[i-j]==nums[i+j]) dp[i-j][i+j]=true;
            else break;
        }
        if(nums[i]!=nums[i+1]) continue;
        for(int j = 1; i-j>=0 && i+j+1<n; ++j){
            if(nums[i-j]==nums[i+1+j]) dp[i-j][i+1+j]=true;
            else break;
        }
    }

    cin>>m;
    for(int i=0; i<m; ++i){
        cin>>start>>end;
        if(end-start == 1){
            if(nums[start-1]==nums[end-1]) cout<<1<<"\n";
            else cout<<0<<"\n";
        }
        else if(dp[start-1][end-1]) cout<<1<<"\n";
        else cout<<0<<"\n";
    }
}