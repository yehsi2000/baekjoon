#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
int n;
bool visited[100001];
pair<int,int> dfs(pair<int,int> start, vector<vector<pair<int,int>>> &tree){
    stack<pair<int,int>> st;
    for(int i=0; i<n+1; ++i) visited[i] = false;
    pair<int,int> furthest = start;
    st.push(start);
    visited[start.first] = true;
    while(!st.empty()){
        int top = st.top().first;
        int dist = st.top().second;
        if(dist>furthest.second) furthest = st.top();
        st.pop();
        for(int i=0; i<tree[top].size();++i){
            int end = tree[top][i].first;
            int weight = tree[top][i].second;
            if(visited[end]) continue;
            visited[end] = true;
            st.push({end,weight+dist});
        }
    }
    return furthest;
}
int main(){
    scanf("%d", &n);
    vector<vector<pair<int,int>>> tree(n+1);
    for(int i=0; i<n; ++i){
        int u, v, w=0;
        scanf("%d", &u);
        while(true){
            scanf("%d", &v);
            if(v==-1) break;
            scanf("%d", &w);
            tree[u].push_back({v,w});
        }
    }
    pair<int,int> furthest = dfs({1,0},tree);
    furthest = dfs({furthest.first,0},tree);
    printf("%d", furthest.second);
}