#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node{
    int zeroLoc;
    vector<int> nextZeros;
};

vector<int> board(9);

int mdMapping[9][9];
int moveMapping[9][4];

void GenerateManhattanMapping(){
    for(int loc1=0; loc1<9; ++loc1){
		for(int loc2=0; loc2<9; ++loc2){
            mdMapping[loc1][loc2] = abs((loc1/3) - (loc2/3)) //y dif
             + abs((loc1 % 3) - (loc2 % 3)); //x dif
		}
	}
}

void GenerateMoveMapping(){
	int moves[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	int tmpboard[3][3];
	for(int y = 0; y<3; ++y){
		for(int x = 0; x<3; ++x){
			tmpboard[y][x] = y*3 + x;
		}
	}
	int move;
	for(int y = 0; y<3; ++y){
		for(int x = 0; x<3; ++x){
			for(int i = 0; i<4; ++i){
				int moveX = moves[i][0];
				int moveY = moves[i][1];
				if(x+moveX>=0 && y+moveY>=0 && x+moveX<3 && y+moveY<3)
					move = tmpboard[y+moveY][x+moveX];
				else move = -1;
				moveMapping[x+y*3][i] = move;
			}
		}
	}
}

int ManhattanDist(){
    int md = 0;
    for(int i=0; i<9; ++i){
        if(board[i]==0) continue;
        md += mdMapping[i][board[i]-1]; //[current location][original location of number]
    }
    return md;
}

bool Solvable(){
    int inversionCnt=0;
	for(int i=0; i<8; i++){
        for (int j=i+1; j<9; j++) 
            if(board[i]>board[j] && board[i]!=0 && board[j]!=0) inversionCnt++;
             
    }
    //n=3 is odd, even number of inversion can solve the puzzle
    if(inversionCnt%2==0)return true;
    else return false;
}

pair<bool,int> IdAStar(int gVal, int lastmove, int bound, int zeroLoc){
    int hVal = ManhattanDist();
    int fVal = gVal + hVal;
    if(hVal==0) return {true, fVal};
    if(fVal > bound){ return {false,fVal};}

    int minMove = 999999;
    for(int move=0; move<4; ++move){
        if(lastmove!=-1 && abs(lastmove-move)==2) continue;
        int newZeroLoc = moveMapping[zeroLoc][move];
        if(newZeroLoc==-1) continue;
        swap(board[zeroLoc],board[newZeroLoc]);
        pair<bool,int> res = IdAStar(gVal+1, move, bound, newZeroLoc);
        swap(board[zeroLoc],board[newZeroLoc]);
        minMove = min(res.second,minMove);
        if(res.first){
            return {true,minMove};
        }
    }
    return {false, minMove};
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i=0; i<9; ++i) {
        cin>>board[i];
    }
    if(!Solvable()){
        cout<<-1;
        return 0;
    }
    GenerateManhattanMapping();
    GenerateMoveMapping();
    
    int bound = ManhattanDist(); //heuristic of initial board
    int zeroLoc = find(board.begin(),board.end(),0)-board.begin();
    while(1){
        //<found? , fval>
        pair<bool,int> res = IdAStar(0, -1, bound,zeroLoc);
        if(res.first) {
            cout<<res.second;
            break;
        }
        bound = res.second; //increase search depth
    }
}