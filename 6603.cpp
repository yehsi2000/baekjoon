//로또 실2
#include <cstdio>

int k;
int testcase[13];

void selectcase(int startidx, int nth){
    static int selection[6]={0,};
    if(nth==6){
        for(int i=0;i<6;++i){
            printf("%d", selection[i]);
            (i!=5) ? printf(" ") : printf("\n");
        }
        return;
    }

    for(int i=startidx; i<k-(5-nth); ++i){
        selection[nth] = testcase[i];
        selectcase(i+1,nth+1);
    }
}

int main(){
    
    while(1){
        scanf("%d", &k);
        if(k==0) break;
        for(int i=0;i<k;++i)
            scanf("%d", testcase+i);
        selectcase(0,0);
        printf("\n");
    }

    return 0;
}