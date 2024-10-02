#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <bitset>
#include <algorithm>
using namespace std;
int board[9][9];
int sudoku[9][3][3];
vector<pair<int,int>> emptylist;
bool printed = false;

pair<int,int> sudokuToBoard(int sudokuidx, int r, int c){
    return {(sudokuidx/3)*3+r,(sudokuidx%3)*3+c};
}

array<int,3> boardToSudoku(int r, int c){
    return array<int,3> {(r/3)*3+c/3,r%3,c%3};
}

bool check(int r, int c, int num){
    int sudokuidx = boardToSudoku(r,c)[0];
    for(int i=0; i<9; ++i){
        if(board[r][i]==num) return false;
        if(board[i][c]==num) return false;
        if(sudoku[sudokuidx][i/3][i%3]==num) return false;
    }
    return true;
}

void fillempty(int idx){
    if(printed) return;
    if(idx==emptylist.size()) {
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(j!=0) cout<<" ";
                cout<<board[i][j];
            }
            if(i!=8) cout<<"\n";
        }
        printed = true;
        return;
    }
    int r = emptylist[idx].first;
    int c = emptylist[idx].second;
    for(int i=1; i<=9; ++i){
        if(check(r,c,i)){
            board[r][c] = i;
            array<int,3> trans = boardToSudoku(r,c);
            sudoku[trans[0]][trans[1]][trans[2]] = i;
            fillempty(idx+1);
            board[r][c] = 0;
            sudoku[trans[0]][trans[1]][trans[2]] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i=0; i<9; ++i){
        int n = i/3;
        for(int j=0; j<3; ++j){
            int tmp;
            cin>>tmp;
            board[i][j] =tmp;
            sudoku[n*3][i%3][j] = tmp;
            if(tmp==0) {
                emptylist.push_back({i,j});
            }
        }
        for(int j=0; j<3; ++j){
            int tmp;
            cin>>tmp;
            board[i][j+3] = tmp;
            sudoku[n*3+1][i%3][j] = tmp;
            if(tmp==0) {
                emptylist.push_back({i,j+3});
            }
        }
        for(int j=0; j<3; ++j){
            int tmp;
            cin>>tmp;
            board[i][j+6] = tmp;
            sudoku[n*3+2][i%3][j] = tmp;
            if(tmp==0) {
                emptylist.push_back({i,j+6});
            }
        }
    }
    fillempty(0);
    
    return 0;
}