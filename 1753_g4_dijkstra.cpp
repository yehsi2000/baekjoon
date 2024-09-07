#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main(){
    int v,e, start;
    scanf("%d %d %d", &v, &e, &start);
    multimap<int,pair<int,int>> edge;
    for(int i=0;i<e;++i){
        int s, e, w;
        scanf("%d %d %d", &s, &e, &w);
        edge.insert({s,{e,w}});
    }

    vector<int> dist(v+1,INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});

    while(!pq.empty()){
        pair<int,int> front= pq.top();
        pq.pop();
        for(auto i = edge.lower_bound(front.second); i!=edge.upper_bound(front.second); ++i){
            int end = (*i).second.first;
            int weight = (*i).second.second;
            if(dist[end] > front.first+weight) {
                dist[end] = front.first + weight;
                pq.push({dist[end],end});
            }   
        }   
    }

    for(int i=1; i<=v; ++i){
        if(dist[i]==INT_MAX) printf("INF\n");
        else printf("%d\n", dist[i]);
    }
    
    return 0;
}