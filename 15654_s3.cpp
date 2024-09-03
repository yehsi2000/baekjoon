#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;
int n, m;
int list[8] = {0,};
bool visited[8] = {false,};
deque<int> printlist;

void dfs(int depth){
    if(depth == m){
        for(int e : printlist) printf("%d ", e);
        printf("\n");
    }

    for(int i=0; i<n; ++i){
        if(visited[i]) continue;
        visited[i] = true;
        printlist.push_back(list[i]);
        dfs(depth+1);
        printlist.pop_back();
        visited[i] = false;
    }
}

int main(){    
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;++i){
        scanf("%d", &list[i]);
    }
    sort(list, list+n);
    dfs(0);
}