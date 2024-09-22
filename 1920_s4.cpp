#include <cstdio>
#include <unordered_set>
using namespace std;
int main(){
    int n,m;
    scanf("%d", &n);
    unordered_set<int> exists;
    while(n--){
        int tmp;
        scanf(" %d", &tmp);
        exists.insert(tmp);
    }
    scanf("%d", &m);
    while(m--){
        int tmp;
        scanf(" %d", &tmp);
        if(exists.find(tmp)!=exists.end()){
            printf("1\n");
        } else {
            printf("0\n");
        }

    }
}