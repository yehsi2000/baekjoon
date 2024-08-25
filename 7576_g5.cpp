#include <cstdio>
#include <queue>

using namespace std;

struct pos{
    int y,x,depth;
};

int array[1000][1000];
int dist[1000][1000];
queue<pos> target;

void spreadTomato(const pos &current, const int &dy, const int &dx){
    int calced_dist = dist[current.y + dy][current.x + dx];
    if(calced_dist > 0) {
        target.push({current.y + dy, current.x + dx, calced_dist > current.depth+1 ? current.depth+1 : calced_dist});
        dist[current.y + dy][current.x + dx] = calced_dist > current.depth+1 ? current.depth+1 : calced_dist;
    }
    else if (calced_dist<0) {
        target.push({current.y + dy, current.x + dx, current.depth+1});
        dist[current.y + dy][current.x + dx] = current.depth+1;
    }
    array[current.y + dy][current.x + dx] = 1;
}

int main(void){
    int n,m;
    
    scanf("%d %d",&m, &n);
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            dist[i][j]=-1;
            scanf("%d",&array[i][j]);
            if(array[i][j]==1){
                target.push({i,j,0});
                dist[i][j]=0;
            }
            if(array[i][j]==-1)
                dist[i][j]=-2;
        }
    }

    
    while(!target.empty()){
        int len = target.size();
        for(int i=0;i<len;++i){
            pos current = target.front();
            target.pop();
            if(current.x>0 && array[current.y][current.x-1] == 0 ) {
                spreadTomato(current, 0 , -1);
            }
            if(current.y>0 && array[current.y-1][current.x] == 0) {
                spreadTomato(current, -1 , 0);
            }
            if(current.x<m-1 && array[current.y][current.x+1] == 0){
                spreadTomato(current, 0, 1);
            }
            if(current.y<n-1 && array[current.y+1][current.x] == 0){
                spreadTomato(current, 1 , 0);
            }
        }
    }
    int smallest=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j) {
            if(dist[i][j]==-1) {
                printf("-1");
                return 0;
            }
            if(dist[i][j]>smallest) smallest = dist[i][j];
        }
    }
    printf("%d", smallest);


}