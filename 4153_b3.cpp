#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int num[3];
    while(1){
        scanf("%d %d %d", &num[0], &num[1], &num[2]);
        if(num[0]==0 && num[1]==0 && num[2]==0) break;
        sort(num,num+3);
        if(num[2]*num[2] == num[1]*num[1] + num[0]*num[0]){
            printf("right\n");
        } else {
            printf("wrong\n");
        }
    }

}