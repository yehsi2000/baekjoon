#include <cstdio>
#include <climits>
#define MAX 987654321
using namespace std;
int dist[1001][1001];

int main(){
    int n,m,x;
    scanf("%d %d %d",&n, &m, &x);
    
    for(int i=1; i<=n; ++i) 
        for(int j=1; j<=n; ++j)
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = MAX;
    
    for(int i=0; i<m; ++i){
        int s, e, t;
        scanf("%d %d %d", &s, &e, &t);
        dist[s][e] = t;
    }
    
    for(int m=1; m<=n; ++m){
        for(int s=1; s<=n; ++s){
            for(int e=1; e<=n; ++e){
                if(dist[s][e] > dist[s][m] + dist[m][e])
                    dist[s][e] = dist[s][m] + dist[m][e];
            }
        }
    }
    

    int max = 0;
    for(int i=1; i<=n; ++i){
        if(dist[i][x]!=MAX && dist[x][i]!=MAX && max<dist[i][x] + dist[x][i]) max = dist[i][x] + dist[x][i];
    }

    printf("%d", max);
}