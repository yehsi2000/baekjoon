#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int board[9][9];
vector<pair<int,int>> zerolist;

bool done = false;
void fillzero(int idx){
    if(done) return;
    if(idx == zerolist.size()){
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                cout<<board[i][j];
            }
            cout<<"\n";
        }
        done = true;
        return;
    }
    pair pos = zerolist[idx];
    bool occupied[11] = {};
    for(int i=0; i<9; ++i){
        occupied[board[pos.first][i]] = true;
        occupied[board[i][pos.second]] = true;
    }
    int sudokuR = pos.first/3;
    int sudokuC = pos.second/3;
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            occupied[board[sudokuR*3+i][sudokuC*3+j]] = true;
        }
    }
    for(int i=1; i<=9; ++i){
        if(!occupied[i]){
            board[pos.first][pos.second] = i;
            fillzero(idx+1);
            board[pos.first][pos.second] = 0;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("E:\\dev\\cpptest\\baekjoon\\input.txt","r",stdin);
    
    for(int i=0; i<9; ++i){
        string tmp;
        cin>>tmp;
        for(int j=0; j<9; ++j){
            board[i][j] = tmp[j]-'0';
            if(board[i][j]==0) zerolist.push_back({i,j});
        }
    }

    fillzero(0);
}