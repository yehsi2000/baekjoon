#include <cstdio>
#include <cstring>
#include <set>

int main(void){   
    int m;

    scanf("%d", &m);
    std::set<int> S;
    while(m--){
        char op[7];
        int num;
        scanf("%s %d",op, &num);
        if(strcmp(op,"add")==0){
            S.insert(num);
        } else if(strcmp(op,"remove")==0){
            S.erase(num);
        } else if(strcmp(op,"check")==0){
            if(S.find(num)!=S.end()) printf("1\n");
            else printf("0\n");
        } else if(strcmp(op,"toggle")==0){
            if(S.find(num)!=S.end()) S.erase(num);
            else S.insert(num);
        } else if(strcmp(op,"all")==0){
            S = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
        } else if(strcmp(op,"empty")==0){
            S = std::set<int>();
        }
    }
    return 0;
}