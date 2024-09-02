#include <cstdio>
#include <queue>
using namespace std;
bool visited[100001] = {false};
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    queue<pair<int,int>> q;
    
    q.push({k,0});
    while(!q.empty()){
        pair<int,int> front = q.front();
        q.pop();
        visited[front.first] = true;
        if(front.first == n){
            printf("%d", front.second);
            return 0;
        }
        if(((front.first&1)==0) && !visited[front.first>>1] ) q.push({front.first/2,front.second+1});
        if(front.first<=100001 && !visited[front.first+1]) q.push({front.first+1,front.second+1});
        if(front.first>0 && !visited[front.first-1]) q.push({front.first-1,front.second+1});
    }
    return 0;    
}