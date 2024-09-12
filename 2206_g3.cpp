#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;
struct Point{
    Point(int X, int Y, bool B):x(X),y(Y),broke(B){};
    int x,y;
    bool broke;  
};
int n, m;
int map[1000][1000];

int find(Point start, Point end){
    queue<Point> q;
    vector<vector<int>> d(n,vector<int>(m,INF));
    d[start.y][start.x] = 1;
    q.push(start);
    int min = 0;
    while(!q.empty()){
        Point e = q.front();
        q.pop();
        if(e.x>0){
            if(map[e.y][e.x-1]==1 ) {
                if(!e.broke && d[e.y][e.x-1] > d[e.y][e.x] + 1){
                    d[e.y][e.x-1] = d[e.y][e.x] + 1;
                    q.push(Point(e.x-1,e.y,true));
                }
            }
            else {
                if(d[e.y][e.x-1] > d[e.y][e.x] + 1){
                    d[e.y][e.x-1] = d[e.y][e.x] + 1;
                    q.push(Point(e.x-1,e.y,e.broke));
                }
            }
        } 
        if(e.y>0){
            if(map[e.y-1][e.x]==1) {
                if(!e.broke && d[e.y-1][e.x] > d[e.y][e.x] + 1){
                    d[e.y-1][e.x] = d[e.y][e.x] + 1;
                    q.push(Point(e.x,e.y-1,true));
                }
                    
            }
            else {
                if(d[e.y-1][e.x] > d[e.y][e.x] + 1){
                    d[e.y-1][e.x] = d[e.y][e.x] + 1;
                    q.push(Point(e.x,e.y-1,e.broke));
                }
            }
        } 
        if(e.x<m-1){
            if(map[e.y][e.x+1]==1) {
                if(!e.broke && d[e.y][e.x+1] > d[e.y][e.x] + 1){
                    d[e.y][e.x+1] = d[e.y][e.x] + 1;
                    q.push(Point(e.x+1,e.y,true));
                }
            }
            else {
                if(d[e.y][e.x+1] > d[e.y][e.x] + 1){
                    d[e.y][e.x+1] = d[e.y][e.x] + 1;
                    q.push(Point(e.x+1,e.y,e.broke));
                }
            }
        } 
        if(e.y<n-1){
            if(map[e.y+1][e.x]==1) {
                if(!e.broke && d[e.y+1][e.x] > d[e.y][e.x] + 1){
                    d[e.y+1][e.x] = d[e.y][e.x] + 1;
                    q.push(Point(e.x,e.y+1,true));
                }
            }
            else {
                if(d[e.y+1][e.x] > d[e.y][e.x] + 1){
                    d[e.y+1][e.x] = d[e.y][e.x] + 1;
                    q.push(Point(e.x,e.y+1,e.broke));
                }
            } 
        }

    }
    return d[end.y][end.x];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; ++i){
        string input;
        cin>>input;
        for(int j=0; j<m; ++j){
            map[i][j] = input[j]-'0';
        }
    }
    Point start = {0,0,false};
    Point end = {m-1, n-1, false};
    int fromStart = find(start, end);
    int fromEnd =find(end, start);
    int res = min(fromStart, fromEnd);
    if(res==INF) cout<< (-1);
    else cout<<res;
    

}