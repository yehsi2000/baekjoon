#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 999999999
using namespace std;
int n;
int cities[10][10];
bool visited[10] = {false,};
int mindist;
int begincity;

void visit_next(int start, int visitcnt, int dist){
    if(visitcnt == n){
        if(cities[start][begincity]) mindist = min(mindist,dist+cities[start][begincity]);
    }
    for(int i=0; i<n; ++i){
        if(visited[i]) continue;
        if(cities[start][i] && dist+cities[start][i]<mindist){
            visited[i] = true;
            visit_next(i,visitcnt+1,dist+cities[start][i]);
            visited[i] = false;
        }
    }

}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>> cities[i][j];
        }
    }
    mindist = MAX;
    for(int i=0; i<n; ++i){
        visited[i] = true;
        begincity = i;
        visit_next(i,1,0);
        visited[i] = false;
    }
    
    cout<<mindist;
}