#include <cstdio>

int n, white_cnt, blue_cnt;
int paper[16384];

void check(int size, int xs, int ys){
    if (size == 1){
        paper[ys*n+xs] ? blue_cnt++ : white_cnt++;
        return;
    }
    int val = paper[ys*n+xs];
    bool same = true;
    for(int i=ys*n+xs;i<(ys+size-1)*n+xs+size;){
        int x = i%n, y=i/n;
        if(paper[i]!=val){
            check(size/2, xs, ys);
            check(size/2, xs+size/2, ys);
            check(size/2, xs, ys+size/2);
            check(size/2, xs+size/2, ys+size/2);
            same = false;
            break;
        }
        if(x==xs+size-1) i=(y+1)*n+xs;
        else i++;
    }
    if(same){
        val ? blue_cnt++ : white_cnt++;
    }
    return;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n*n;++i){
        scanf("%d", paper+i);
    }
    check(n, 0, 0);
    printf("%d\n%d", white_cnt, blue_cnt);
}