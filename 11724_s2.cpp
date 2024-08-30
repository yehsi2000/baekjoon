#include <cstdio>
#include <queue>

using namespace std;
bool visited[1001];
bool list[1001][1001];
queue<int> q;

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; ++i){
        int a,b;
        scanf("%d %d", &a, &b);
        list[a][b] = true;
        list[b][a] = true;
    }
    int connected = 0;
    for(int i=1; i<=n; ++i){
        if(visited[i]) continue;
        q.push(i);
        visited[i] = true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(int j=1;j<=n;++j){
                if(list[front][j] && !visited[j]){
                    visited[j]=true;
                    q.push(j);
                }
            }
        }
        connected++;
    }
    printf("%d", connected);
}