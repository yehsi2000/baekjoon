#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int r,c, maxdepth=1;
int dp[20][20];
vector<vector<int>> board;
pair<int,int> dir[4] = {{0,1},{-1,0},{0,-1},{1,0}};


void dfs(pair<int,int> pos, int depth, int visited){
    visited |= (1<<board[pos.first][pos.second]);
    if(dp[pos.first][pos.second]==visited) return;
    maxdepth = max(maxdepth,depth);
    dp[pos.first][pos.second]=visited;

    for(auto d : dir){
        pair<int,int> newpos = {pos.first + d.first, pos.second + d.second};
        if(newpos.first>=r || newpos.first<0 || newpos.second>=c || newpos.second<0 || (visited & (1<<board[newpos.first][newpos.second]))) continue;
        dfs(newpos, depth+1,visited);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>r>>c;
    board = vector<vector<int>>(r,vector<int>(c));
    for(int i=0; i<r; ++i){
        string temp;
        cin>>temp;
        for(int j=0; j<c; ++j){
            board[i][j] = temp[j]-'A';
        }
    }
    dfs({0,0},1,0);
    cout<<maxdepth;
    
}