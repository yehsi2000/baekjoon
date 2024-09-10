#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool fw(int n, vector<vector<int>> dist){
    for(int mid=0; mid<n; ++mid){
        for(int start=0; start<n; ++start){
            for(int end=0; end<n; ++end){
                if (dist[start][end] > dist[start][mid]+dist[mid][end])
                    dist[start][end] = dist[start][mid]+dist[mid][end];
                if(start==end && dist[start][end]<0) return true;
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
        vector<vector<int>> dist(n, vector<int>(n,30000000));
        for(int j=0; j<m; ++j){
            int s,e,t;
            scanf("%d %d %d", &s, &e, &t);
            dist[s-1][e-1] = min(dist[s-1][e-1],t);
            dist[e-1][s-1] = min(dist[e-1][s-1],t);
        }
        for(int j=0; j<w; ++j){
            int s,e,t;
            scanf("%d %d %d", &s, &e, &t);
            dist[s-1][e-1] = -t;
        }
        if(fw(n, dist))
            printf("YES\n"); 
        else
            printf("NO\n");
    }

}