#include <cstdio>

bool selfcheck[10001] = {false};

int main(){
    for(int i=1;i<=10000;++i){
        int sum=i;
        int num=i;
        while(num>0){
            sum+=num%10;
            num/=10;
        }
        selfcheck[sum]=true;
    }
    for(int i=1;i<=10000;++i){
        if(!selfcheck[i]) printf("%d\n", i);
    }
    return 0;
}