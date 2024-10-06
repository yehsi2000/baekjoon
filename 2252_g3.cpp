#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("E:\\dev\\cpptest\\baekjoon\\input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    vector<int> incnt(n+1);
    for(int i=0; i<m; ++i){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        incnt[b]++;
    }
    deque<int> dq;
    for(int i=1; i<=n; ++i){
        if(incnt[i]==0) dq.push_back(i);
    }
    while(!dq.empty()){
        int front = dq.front();
        dq.pop_front();
        cout << front << " ";
        for(int e: graph[front]){
            incnt[e]--;
            if(incnt[e]==0) dq.push_back(e);
        }
    }
}