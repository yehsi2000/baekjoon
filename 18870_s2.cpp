#include <cstdio>
#include <algorithm>

using namespace std;

struct S{
    int num,index;
    bool operator<(const S &ns){
        return num < ns.num;
    }
};

S list[1000001];
int mapping[1000001];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &list[i].num);
        list[i].index = i;
    }
    sort(list, list+n);
    int comp=0;
    for(int j=0;j<n;++j){
        mapping[list[j].index] = comp;
        if(list[j+1].num != list[j].num) comp++;
    }
    for(int i=0; i<n; ++i){
        printf("%d ",mapping[i]);
    }
}