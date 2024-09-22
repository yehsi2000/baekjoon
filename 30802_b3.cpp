#include <cstdio>
int shirt[6];
int main(){
    int n,t,p;
    scanf("%d", &n);
    for(int i=0; i<6; ++i) scanf("%d", &shirt[i]);
    int shirtcnt=0;
    scanf("%d %d", &t, &p);
    for(int i=0; i<6; ++i){
        if(shirt[i]>=t) shirtcnt += shirt[i]/t;
        if(shirt[i]%t) shirtcnt++;
    }
    printf("%d\n%d %d",shirtcnt, n/p, n%p);
}