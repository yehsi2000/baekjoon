#include <cstdio>
const int E = 15;
const int S = 28;
const int M = 19;
int main(){
    int e,s,m;
    scanf("%d %d %d", &e, &s, &m);
    while(1){
        if((e-1)%S ==s-1 && (e-1)%M == m-1) break;
        e+=E;
    }
    printf("%d", e);
}