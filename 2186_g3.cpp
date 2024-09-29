#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int n, m, k;
string board="";
string target;
vector<vector<int>> dp;

int dfs(int pos, int wordindex){
    if(wordindex==target.length()){
        return 1;
    }
    if(dp[pos][wordindex] != -1){
        return dp[pos][wordindex];
    } 

    dp[pos][wordindex] = 0;

    int x = pos%m;
    int y = pos/m;
    for(int i=1; i<=k; ++i){
        if(x+i<m && board[pos+i]==target[wordindex]){
            dp[pos][wordindex] += dfs(pos+i,wordindex+1);
        }
        if(x-i>=0 && board[pos-i]==target[wordindex]) {
            dp[pos][wordindex] += dfs(pos-i,wordindex+1);
        }
        if(y+i<n && board[pos+i*m]==target[wordindex]) {
            dp[pos][wordindex] += dfs(pos+i*m,wordindex+1);
        }
        if(y-i>=0 && board[pos-i*m]==target[wordindex]) {
            dp[pos][wordindex] += dfs(pos-i*m,wordindex+1);
        }
    }
    return dp[pos][wordindex];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(int i=0; i<n; ++i){
        string tmp;
        cin>>tmp;
        board+=tmp;
    }
    cin>>target;
    dp = vector<vector<int>>(n*m,vector<int>(target.length(),-1));
    int cnt = 0;
    for(int i=0; i<n*m; ++i){
        if(board[i] == target[0]){
            cnt += dfs(i,1);
        }
    }

    cout<<cnt;
}