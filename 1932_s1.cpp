#include <cstdio>
#include <algorithm>

int link[500];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        for(int j=i;j>=0;--j) {
            int tmp;
            scanf("%d", &tmp);
            if(j==0) link[j] += tmp;
            else if(j==n-1) link[j-1] + tmp;
            else link[j] = std::max(link[j-1], link[j]) + tmp;
        }
    }
    int max =0;
    for(int i=0; i<n; ++i){
        if(max<link[i]) max = link[i];
    }
    printf("%d", max);
}