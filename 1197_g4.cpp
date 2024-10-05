#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
int parent[2000003];
const int OFFSET = 1000000;

int find(int n){
    if(parent[OFFSET+n] == n) return n;
    return parent[OFFSET+n] = find(parent[OFFSET+n]);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    parent[OFFSET+b] = a;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("E:\\dev\\cpptest\\baekjoon\\input.txt","r",stdin);
    int v,e;
    cin>>v>>e;
    for(int i=1; i<=e; ++i){
        int s,e,w;
        cin>>s>>e>>w;
        pq.push({w,{s,e}});
        parent[OFFSET+i]=i;
    }
    set<int> closed;
    int weightsum = 0;
    while(!pq.empty()){
        pair top = pq.top();
        pair vertpair = top.second;
        pq.pop();
        if(find(vertpair.first)!=find(vertpair.second)){
            unite(vertpair.first,vertpair.second);
            weightsum+=top.first;
        } else {
            continue;
        }
        
    }
    cout<<weightsum;

}