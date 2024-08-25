#include <cstdio>
#include <deque>

struct pos{
    pos(int R, int C):r(R),c(C){};
    int r,c;
};

pos operator+(pos pos1, pos pos2){
    return {pos1.r+pos2.r, pos1.c+pos2.c};
}
bool operator==(pos pos1, pos pos2){
    return (pos1.r==pos2.r && pos1.c==pos2.c);
}

const pos dir[4] = {{0,1},{1,0},{0,-1},{-1,0}}; //우 하 좌 상

struct status{
    status(pos P, int dir) : position(P), direction(dir){};
    pos position;
    int direction;
    pos getdir(){
        return dir[direction];
    }
};

std::deque<pos> apple_pos;
std::deque<pos> ctrls;
std::deque<status> snake;
int time=1;
int board_size;
int apple_cnt;
int ctrl_cnt;
int main(){
    scanf("%d", &board_size);
    scanf("%d", &apple_cnt);
    for(int i=0;i<apple_cnt;++i){
        int tr,tc;
        scanf("%d %d", &tr, &tc);
        apple_pos.push_back(pos(tr, tc));
    }

    scanf("%d", &ctrl_cnt);

    for(int i=0;i<ctrl_cnt;++i){
        int t; 
        char dir;
        scanf("%d %c", &t, &dir);
        if(dir == 'L') ctrls.push_back(pos(t,-1));
        else if(dir == 'D') ctrls.push_back(pos(t,1));
    }

    snake.push_front(status(pos(1,1),0)); //1,1 우향
    int input_idx=0;
    do{
        snake.push_front(status(pos(snake.front().position + snake.front().getdir()) ,snake.front().direction));

        pos current_pos = snake.front().position;
        if(current_pos.r==0 || current_pos.r>board_size || current_pos.c==0 || current_pos.c>board_size){
            printf("%d", time);
            return 0;
        }
        for(auto body = snake.begin()+1; body!=snake.end();body++){
            if(body->position == current_pos){
                printf("%d",time);
                return 0;
            }
        } 
        bool ate = false;
        for(std::deque<pos>::iterator apple = apple_pos.begin(); !apple_pos.empty() && apple!=apple_pos.end();apple++){
            if(snake.front().position == *apple){
                ate=true;
                std::deque<pos>::iterator ret = apple_pos.erase(apple);

                if(ret==apple_pos.end())
                    break;
            }
        }
        if(ate == false) snake.pop_back();
        
        if(!ctrls.empty() && ctrls.front().r == time) {
            int nextdir = snake.front().direction + ctrls.front().c; //apply control
            if(nextdir==4) 
                nextdir=0;
            if(nextdir==-1) 
                nextdir=3;
            snake.front().direction = nextdir;
            ctrls.pop_front();
        }
    } while(++time);
}