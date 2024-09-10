#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct Edge{
    int start;
    int end;
    int val;
};

int dist[501] = {0,}; //모든 정점에서 시작하면 됨

bool bellford(int n, vector<Edge> graph){
    for(int i=1; i<=n; ++i){
        for(int j=0; j<graph.size();++j){
            if(dist[graph[j].start] == INT_MAX) continue; //시작지점에서 도달할 수 없는 음수 사이클을 못찾음 이걸빼면 맞는이유는 다 INTMAX를 무한대가 아니라 그냥 INT_MAX짜리 거리로 생각하고 벨만포드 돌려서 INT MAX로 하면 연산을 해버리니까 오버플로우 나서 틀린거였음
            if(dist[graph[j].end] > dist[graph[j].start] + graph[j].val){
                dist[graph[j].end] = dist[graph[j].start] + graph[j].val;
                if(i==n) {
                    return true;
                }
            }
        }
    }
    return false;
}


int main(){
    int tcnum;
    scanf("%d", &tcnum);
    for(int i=0; i<tcnum; ++i){
        int n,m,w;
        scanf("%d %d %d", &n, &m, &w);
        vector<Edge> edges;
        for(int j=0; j<m; ++j){
            int s,e,t;
            scanf("%d %d %d", &s, &e, &t);
            edges.push_back({s,e,t});
            edges.push_back({e,s,t});
        }
        for(int j=0; j<w; ++j){
            int s,e,t;
            scanf("%d %d %d", &s, &e, &t);
            edges.push_back({s,e,-t});
        }
        if(bellford(n, edges))
            printf("YES\n"); 
        else
            printf("NO\n");
    }

}