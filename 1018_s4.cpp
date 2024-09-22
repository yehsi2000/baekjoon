#include <cstdio>
#include <algorithm>
using namespace std;
char board[50][50];

int cntrepaint(int starty, int startx){
    int blackcnt=0;
    int whitecnt=0;
    for(int y=0;y<8; ++y){
        for(int x=0;x<8; ++x){
            if((x+y)%2 && board[starty+y][startx+x] != 'W') blackcnt++;
            else if((x+y)%2==0 && board[starty+y][startx+x] != 'B') blackcnt++;
            
            if((x+y)%2 && board[starty+y][startx+x] != 'B') whitecnt++;
            else if ((x+y)%2==0 && board[starty+y][startx+x] != 'W') whitecnt++;
        }
    }
    return min(blackcnt, whitecnt);
        
}

int main(){
    int n,m, minpaint=9999;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) scanf(" %c", &board[i][j]);
    for(int i=0; i<n-7; ++i){
        for(int j=0; j<m-7; ++j){
            minpaint = min(cntrepaint(i,j),minpaint);
        }
    }
    printf("%d", minpaint);
}