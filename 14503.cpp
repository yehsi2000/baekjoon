#include <cstdio>

int room[50][50] = {0,};
int direction[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int cleaned = 0;
int n, m, robo_x, robo_y, robo_dir;

bool isNearDirty(){
    for(int i=0;i<4;++i){
        if(room[robo_x + direction[i][0]][robo_y] == 0 || room[robo_x][robo_y + direction[i][1]] == 0){
            return true; // dirty
        }
    }
    return false; //clean
}

void roboBehav(){
    //clean current dirty position : behavior no.1
    if(room[robo_x][robo_y] == 0){
        cleaned++;
        room[robo_x][robo_y] = 2; //cleaned
    }
    if(!isNearDirty()){ //all nearby positions are clean : behavior no.2
        if(room[robo_x - direction[robo_dir][0]][robo_y - direction[robo_dir][1]] == 1) //hit the wall
            return; //stop
        else {
            robo_x -= direction[robo_dir][0];
            robo_y -= direction[robo_dir][1];
            roboBehav();
        }
    } else { //rotate 90degree CCW, if front dirty move forward : behavior no.3
        robo_dir = --robo_dir < 0 ? robo_dir+4 : robo_dir; //rotate 90 CCW
        if(room[robo_x+direction[robo_dir][0]][robo_y+direction[robo_dir][1]]==0){ // if front dirty
            robo_x += direction[robo_dir][0];
            robo_y += direction[robo_dir][1];
        } 
        roboBehav();
    }
}

int main(){
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &robo_x, &robo_y, &robo_dir);
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) scanf("%d", &room[i][j]); //get room status input
    roboBehav(); //start robot
    printf("%d", cleaned);
}