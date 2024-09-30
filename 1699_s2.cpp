#include <cstdio>
bool squared[100001] = {false,};
bool squaredsum[100001] = {false,};
int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i*i<100001;++i){
        squared[i*i] = true;
    }
    for(int i=1; i*i<100001; ++i){
        for(int j=i; i*i + j*j <100001; ++j){
            squaredsum[i*i+j*j] = true;
        }
    }
    if(squared[n]){
        printf("1");
    } else if(squaredsum[n]){
        printf("2");
    } else {
        for(int i=1; i*i<=n; ++i){
            if(squaredsum[n-i*i]){
                printf("3");
                return 0;
            }
        }
        printf("4");
    }
}