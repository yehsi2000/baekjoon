#include <cstdio>

int main(){
    int n,k;
    int res = 1;
    scanf("%d %d", &n, &k);
    for(int i=0;i<k;++i){
        res *= n-i;
        res /= i+1;
    }
    printf("%d", res);
}