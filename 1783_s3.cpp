#include <cstdio>
#include <algorithm>
using namespace std;
int findway(int height, int width){
    if(height<2 || width <2) return 1;
    if(height <3 || width<7 ){
        if(height<3) {
            return min((width-1)/2+1,4);
        }
        else return min(width,4);    
    } else return width-2;
}

int main(){
    int height, width;
    scanf("%d %d", &height, &width);
    printf("%d", findway(height, width));
}