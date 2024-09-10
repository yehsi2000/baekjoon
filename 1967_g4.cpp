#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
int n;

pair<int,int> dfs(vector<pair<int,int>>* list, bool* visited, pair<int,int> start){
    stack<pair<int,int>> st;
    pair<int,int> max={0,0};
    st.push(start);
    while(!st.empty()){
        pair<int,int> topPair = st.top();
        st.pop();
        if(visited[topPair.first]) continue;
        visited[topPair.first] = true;
        if(max.second < topPair.second) max = topPair;
        for(auto e : list[topPair.first]){
            if(visited[e.first]) continue;
            st.push({e.first,topPair.second + e.second});
        }
    }
    return max;
}

int main(){
    scanf("%d", &n);
    vector<pair<int,int>> list[n+1];
    bool* visited = new bool[n+1];

    for(int i=0; i<=n; ++i) visited[i]=false;
    
    for(int i=0; i<n-1;++i){
        int parent, child, w;
        scanf("%d %d %d", &parent, &child, &w);    
        list[parent].push_back({child,w});
        list[child].push_back({parent,w});
    }
    //find furthest from root
    pair<int,int> end = dfs(list, visited, {1,0});
    //from one end to furthest (another end)
    for(int i=0; i<=n; ++i) visited[i]=false;
    pair<int,int> end2 = dfs(list, visited, {end.first, 0});
    printf("%d", end2.second);
    delete[] visited;
    return 0;

}