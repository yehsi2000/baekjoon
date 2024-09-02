#include <cstdio>

int N, r,c;

int divide(int size, int start, int startx, int starty){
    int block = (size*size)>>2;
    if(r < starty+(size/2)) {
        //half upper
        if(c < startx+(size/2)){ 
            //half left
        } else {
            //half right
            start += block;
            startx = startx+size/2;
            starty = starty;
        }
    } else { 
        //half lower
        if(c < startx+(size/2)){ 
            //half left
            start += block*2;
            startx = startx;
            starty = starty+size/2;
        } else {
            //half right
            start += block*3;
            startx = startx+size/2;
            starty = starty+size/2;
        }
    }
    if(size==2) return start;
    else return divide(size/2, start, startx, starty);
}

int main(){    
    scanf("%d %d %d", &N, &r, &c);
    int size = 1<<N;
    printf("%d",divide(size, 0, 0, 0));
    
}