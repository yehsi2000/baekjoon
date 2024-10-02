#include <iostream>
#include <queue>
using namespace std;
bool visited[1000001] = {false,};
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;
    queue<int> q;
    q.push(s);
    int cnt = 0;
    while(!q.empty()){
        int n= q.size();
        for(int i=0; i<n;++i){
            int front = q.front();
            q.pop();
            if(visited[front]) continue;
            visited[front] = true;
            if(front == g){cout<<cnt; return 0;}
            if(front+u<=f && !visited[front+u]) q.push(front+u);
            if(front-d>0 && !visited[front-d]) q.push(front-d);
        }
        cnt++;
    }
    cout<<"use the stairs";
}