#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

struct build{
    int idx;
    int buildtime;
    int requiredbuildtime = 0;
    vector<int> requires;
};

vector<build> buildings;
deque<bool> visited;
deque<int> order;

void dfs(int start){
    if(visited[start]) return;
    visited[start] = true;
    for(int bd : buildings[start].requires){
        if(!visited[bd] ){
            dfs(bd);
        }
    }
    order.push_back(start);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("E:\\dev\\cpptest\\baekjoon\\input.txt","r",stdin);
    int t, n, k, target;
    cin>> t;
    for(int i=0; i<t; ++i){
        cin>>n>>k;
        buildings = vector<build>(n+1);

        for(int j=1; j<=n; ++j){
            cin>>buildings[j].buildtime;
            buildings[j].idx = j;
        }
        
        for(int j=0; j<k; ++j){
            int tmp1, tmp2;
            cin>>tmp1>>tmp2;
            buildings[tmp2].requires.push_back(tmp1);
        }
        cin>>target;
        
        order = deque<int>();
        visited = deque<bool>(n+1,false);

        dfs(target);
        while(!order.empty()){
            build* front = &buildings[order.front()];
            order.pop_front();
            for(int e : front->requires){
                front->requiredbuildtime = max(front->requiredbuildtime, buildings[e].buildtime+buildings[e].requiredbuildtime);
            }

        }
        cout<<buildings[target].buildtime + buildings[target].requiredbuildtime<<"\n";
        
    }
}