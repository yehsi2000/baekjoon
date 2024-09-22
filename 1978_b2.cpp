#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);
    int cnt = 0;
    while(n--){
        int num;
        scanf("%d", &num);
        if(num==1) continue;
        if(num<4) {
            cnt++;
            continue;
        }
        bool flag = true;
        for(int i=2; i<num; ++i){
            if(num%i == 0){
                flag = false;
                break;
            }
        }
        if(flag) cnt++;
        
    }
    printf("%d", cnt);
}