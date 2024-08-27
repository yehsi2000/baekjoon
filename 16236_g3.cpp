#include <cstdio>
#include <queue>

using namespace std;

int aquarium[20][20];
bool searched[20][20] = {false,};
int shark_size=2, n, fish, ate, shortest;

struct state{
    int x,y,dist;
    state(int X, int Y, int D){
        x=X;
        y=Y;
        dist=D;
    }
};

bool operator < (state a, state b){
    if(a.dist > b.dist) return true;
    else if(a.dist == b.dist)
        if(a.y > b.y) 
            return true;
        else if(a.y==b.y) 
            return a.x > b.x;
    else return false;
}

queue<state> bfs;
priority_queue<state> what2eat;

void find_edible(int dx, int dy, state current){
    if(searched[current.y+dy][current.x+dx] == true) return;
    if(aquarium[current.y+dy][current.x+dx] < shark_size && aquarium[current.y+dy][current.x+dx] > 0){ //edible fish
        what2eat.push(state(current.x+dx,current.y+dy,current.dist+1));
    } else if(aquarium[current.y+dy][current.x+dx] > shark_size) return; //not passable

    bfs.push(state(current.x+dx,current.y+dy, current.dist+1));
    searched[current.y+dy][current.x+dx] = true;
    return;
}

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;++i) for(int j=0;j<n;++j) {
        scanf("%d", &aquarium[i][j]); 
        if(aquarium[i][j]>0 && aquarium[i][j]<7) fish++;
        else if (aquarium[i][j]==9){bfs.push(state(j,i,0)); aquarium[i][j]=0;};
    }

    while(bfs.size()!=0){
        int len = bfs.size();
        
        for(int i=0;i<len;++i){
            state current = bfs.front();
            bfs.pop();
            if(fish>0 && current.y>0){ //상
                find_edible(0, -1, current);
            }
            if(fish>0 && current.x>0){ //좌
                find_edible(-1, 0, current);
            }
            if(fish>0 && current.y<n-1){ //하
                find_edible(0, 1, current);
            }
            if(fish>0 && current.x<n-1){ //우
                find_edible(1, 0, current);
            }
        }
        if(!what2eat.empty()){
            state current = what2eat.top();
            bfs = queue<state>();
            what2eat = priority_queue<state>();
            bfs.push(current);
            ate++;
            fish--;
            if(ate==shark_size){
                shark_size++;
                ate = 0;
            }
            aquarium[current.y][current.x] = 0; //ate
            if(current.dist+1>shortest) shortest = current.dist;

            for(int i=0;i<n;++i) for(int j=0;j<n;++j) searched[i][j] = false;
        }
        if(fish==0) break;
    }

    printf("%d", shortest);
}