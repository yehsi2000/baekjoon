#include <cstdio>
#define DIST_MAX 1000000000
int n,m;

int dist[100][100];

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<100;++i){
        for(int j=0;j<100;++j){
            dist[i][j] = DIST_MAX;
        }
    }

    for(int i=0; i<m; ++i){
        int s, e, w;
        scanf("%d %d %d", &s, &e, &w);
        if(dist[s-1][e-1] > w) dist[s-1][e-1]= w;
    }

    for(int m=0; m<n; ++m){
        for(int s=0; s<n; ++s){
            for(int e=0; e<n; ++e){
                if(s==e) continue;
                if(dist[s][e]> dist[s][m] + dist[m][e]) dist[s][e] = dist[s][m] + dist[m][e];
            }
        }
    }

    for(int i=0; i<n; ++i){
        for(int j=0;j<n; ++j){
            printf("%d ",dist[i][j] == DIST_MAX ? 0 : dist[i][j]);
        }
        printf("\n");
    }
}