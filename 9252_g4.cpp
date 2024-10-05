#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1001][1001]={};
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("E:\\dev\\cpptest\\baekjoon\\input.txt","r",stdin);
    string st1;
    string st2;
    cin>>st1>>st2;
    int len1 = st1.length();
    int len2 = st2.length();
    for(int i=1; i<=len1; ++i){
        for(int j=1; j<=len2; ++j){
            if(st1[i-1]==st2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    int size = dp[len1][len2];
    cout<<size;
    if(size==0) return 0;
    string s(size,' ');
    int r=len1,c=len2;
    while(dp[r][c]!=0){
        if(dp[r-1][c] == dp[r][c]) r--;
        else if(dp[r][c-1]==dp[r][c]) c--;
        else {
            s[--size] = st1[r-1];
            r--;c--;
        }
    }
    cout<<"\n"<<s;
}