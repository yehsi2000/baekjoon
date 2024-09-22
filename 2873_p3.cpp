#include <cstdio>
#include <cstdlib>
using namespace std;

void solve(int h, int w){
    int min=1001;
    int minx=0, miny=0;
    for(int i=h-1; i>=0; --i){
        for(int j=0; j<w; ++j){
            int tmp;
            scanf("%d", &tmp);
            if((i+j)%2==0 && min>tmp) {
                min=tmp;
                minx=j;
                miny=i;
            }
        }
    }
    if(h%2){
        for(int i=0; i<h; ++i){
            for(int j=0; j<w-1; ++j){
                if(i%2) printf("L");
                else printf("R");
            }
            if(i<h-1) printf("D");
        }
    } else {
        if(w%2){
            for(int i=0; i<w; ++i){
                for(int j=0; j<h-1; ++j){
                    if(i%2) printf("U");
                    else printf("D");
                }
                if(i<w-1) printf("R");
            }
        } else {
            //w h 모두 짝수
            for(int i=h-1; i>0; i-=2){
                if(miny==i || miny==i-1){
                    for(int i=0; i<minx; ++i){
                        if(i%2 == 0) printf("DR");
                        else printf("UR");
                    }
                    for(int i=minx; i<w-1; ++i){
                        if(i%2 == 0) printf("RD");
                        else printf("RU");

                    }
                } else if(miny>i) {
                    printf("D");
                    //피할곳 지난 다음라인
                    for(int j=0;j<w-1; ++j) printf("L");
                    printf("D");
                    for(int j=0;j<w-1; ++j) printf("R");
                } else {
                    for(int j=0;j<w-1; ++j) printf("R");
                    printf("D");
                    for(int j=0;j<w-1; ++j) printf("L");
                    printf("D");
                }
            }
        }
    }
}

int main(){
    int h,w;
    //freopen("E:\\dev\\cpptest\\baekjoon\\input.txt","r",stdin);
    scanf("%d %d", &h, &w);
    solve(h,w);

}