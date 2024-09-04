#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;

int list[8];
bool visited[8] = {false,};
deque<int> printlist;
int n,m, popped=-1;
void dfs(int depth){
    if(depth == m){
        for(int e : printlist) printf("%d ", e);
        printf("\n");
        return;
    }
    for(int i=0; i<n; ++i){
        if(visited[i]) continue;
        visited[i] = true;
        if(popped==list[i]){
            visited[i] = false;
            continue;
        } else {
            popped = -1;
        }
        printlist.push_back(list[i]);
        dfs(depth+1);
        popped = printlist.back();
        printlist.pop_back();
        visited[i] = false;
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; ++i){
        scanf("%d", &list[i]);
    }
    sort(list, list+n);
    dfs(0);

}