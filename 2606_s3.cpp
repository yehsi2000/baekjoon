#include <cstdio>
#include <queue>

using namespace std;

bool graph[101][101] = {false};
bool visited[101]= {false};
queue<int> q;

int main(){
    int pc_cnt, pair_cnt;
    scanf("%d %d", &pc_cnt, &pair_cnt);

    for(int i=0;i<pair_cnt; ++i){
        int tmpa, tmpb;
        scanf("%d %d", &tmpa, &tmpb);
        graph[tmpa][tmpb] = true;
        graph[tmpb][tmpa] = true;
    }
    q.push(1);
    visited[1] = true;
    int infected=0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        visited[front] = true;
        for(int i=1;i<=pc_cnt;++i){
            if(graph[front][i] && !visited[i]){
                q.push(i);
                visited[i] = true;
                infected++;
            }
        }
    }
    printf("%d", infected);
}