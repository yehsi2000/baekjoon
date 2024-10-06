#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("E:\\dev\\cpptest\\baekjoon\\input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> order(n+1);
    vector<int> incnt(n+1);
    for(int i=0; i<m; ++i){
        int chargecnt;
        cin>>chargecnt;
        int start=0, end=0;
        for(int j=0; j<chargecnt-1; ++j){
            if(!start) cin>>start;
            else start=end;
            cin>>end;
            order[start].push_back(end);
            incnt[end]++;
        }
    }
    queue<int> q;
    vector<int> topologicSorted;
    for(int i=1; i<=n; ++i){
        if(incnt[i]==0) q.push(i);
    }
    while(!q.empty()){
        int front = q.front();
        q.pop();
        topologicSorted.push_back(front);
        for(int e : order[front]){
            incnt[e]--;
            if(incnt[e]==0) q.push(e);
        }
    }
    if(topologicSorted.size()!=n){
        cout<<0;
    } else {
        for(int e: topologicSorted){
            cout << e <<" ";
        }
    }
    
}