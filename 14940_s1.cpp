#include <cstdio>
#include <queue>
#include <utility>

using namespace std;


int array[1000][1000];
int dist[1000][1000];

int main(void){
    int n,m;
    pair<int,int> start;
    scanf("%d %d",&n, &m);
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) {
        dist[i][j]=-1;
        scanf("%d",&array[i][j]);
        if(array[i][j]==2) start = {i,j};
        if(array[i][j]==0) dist[i][j]=0;
    }

    queue<pair<int,int>> target;
    target.push(start);
    int depth=0;
    array[start.first][start.second] = 0;
    while(!target.empty()){
        int len = target.size();
        for(int i=0;i<len;++i){
            pair<int,int> current = target.front();
            target.pop();
            //if(array[current.first][current.second]==0) continue;
            
            dist[current.first][current.second] = depth;
            if(current.first>0 && array[current.first-1][current.second] == 1 ) {
                target.push({current.first-1,current.second});
                array[current.first-1][current.second] = 0;
            }
            if(current.second>0 && array[current.first][current.second-1] == 1) {
                target.push({current.first,current.second-1});
                array[current.first][current.second-1] = 0;
            }
            if(current.first<n-1 && array[current.first+1][current.second] == 1){
                target.push({current.first+1,current.second});
                array[current.first+1][current.second] = 0;
            }
            if(current.second<m-1 && array[current.first][current.second+1] == 1){
                target.push({current.first,current.second+1});
                array[current.first][current.second+1] = 0;
            }
        }
        depth++;
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j) {
            if(j==m-1) printf("%d", dist[i][j]);
            else printf("%d ", dist[i][j]);
        }
        printf("\n");
    }


}