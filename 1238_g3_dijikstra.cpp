#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int n, m;
vector<pair<int,int>> roadFromTo[10001];
vector<int> dist;

void findDist(int start){
    dist = vector<int>(n+1,INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        int weight= pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        for(int i=0; i<roadFromTo[idx].size(); ++i){
            if(dist[roadFromTo[idx][i].first] > weight + roadFromTo[idx][i].second) {
                dist[roadFromTo[idx][i].first] = weight + roadFromTo[idx][i].second;
                pq.push({dist[roadFromTo[idx][i].first],roadFromTo[idx][i].first});
            }
        }
    }
}

int main(){
    int x;
    scanf("%d %d %d",&n, &m, &x);
    for(int i=0; i<m; ++i){
        int s, e, t;
        scanf("%d %d %d", &s, &e, &t);
        roadFromTo[s].push_back({e,t});
    }
    findDist(x);
    vector<int> res(dist);
    for(int i=1;i<=n;++i){
        if(i==x) continue;
        findDist(i);
        res[i]+=dist[x];
    }
    int max = 0;
    for(int i=1; i<=n; ++i){
        if(max<res[i]) max = res[i];
    }
    printf("%d", max);
}