#include <cstdio>
int sumto[100001];
int list[100001];

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    int sum=0;
    for(int i=0; i<n; ++i){
        scanf("%d",&list[i]);
        sum += list[i];
        sumto[i+1] = sum;
    }
    while(m--){
        int s, e;
        scanf("%d %d",&s, &e);
        printf("%d\n", sumto[e]-sumto[s-1]);
    }
}