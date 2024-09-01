#include <cstdio>
#include <queue>

std::priority_queue<int,std::vector<int>,std::greater<int>> q;

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;++i){
        int input;
        scanf("%d",&input);
        if(input==0){
            if(q.empty()) printf("0\n");
            else {
                printf("%d\n",q.top());
                q.pop();
            }
        } else {
            q.push(input);
        }
    }
}