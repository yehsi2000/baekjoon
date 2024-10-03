#include <cstdio>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int n,m;
int board[100][100];
bool visited[100][100];

pair<int,int> movedir[4] = {{0,1},{1,0},{0,-1},{-1,0}};

pair<int,int> operator+(pair<int,int>a, pair<int,int>b){
    return {a.first+b.first, a.second+b.second};
}

struct state{
    pair<int,int> pos;
    int broken;
};

int main(){
    freopen("E:\\dev\\cpptest\\baekjoon\\input.txt","r",stdin);
    
    scanf("%d %d", &m, &n);
	 for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			scanf("%1d", &board[i][j]); 
		}
    deque<state> dq;
    dq.push_front({{0,0},0});
    while(!dq.empty()){
        state cur = dq.front();
        dq.pop_front();
        if(cur.pos.first == n-1 && cur.pos.second == m-1){
            printf("%d",cur.broken);
            break;
        }
        for(int i=0; i<4; ++i){
            pair<int,int> newpos = cur.pos + movedir[i];
            if(newpos.first<0 || newpos.first>=n || newpos.second<0 || newpos.second>=m || visited[newpos.first][newpos.second]) continue;
            visited[newpos.first][newpos.second] = true;
            if(board[newpos.first][newpos.second]){
                dq.push_back({newpos,cur.broken+1});
            } else {
                dq.push_front({newpos,cur.broken});
            }
        }
        
    }
    return 0;
}