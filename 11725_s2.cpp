#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

bool visited[100001] = {false,};

int main(){
    int n;
    scanf("%d", &n);
    vector<vector<int>> conList(n);
    for(int i=1; i<n; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        conList[a-1].push_back(b);
        conList[b-1].push_back(a);
    }
    stack<int> st;
    
    vector<int> parent(n+1);
    st.push(1);
    visited[1] = true;
    while(!st.empty()){
        int sttop = st.top();
        st.pop();
        for(int e : conList[sttop-1]){
            if(visited[e]) continue;
            parent[e]=sttop;
            visited[e] = true;
            st.push(e);
        }   
    }

    for(int i=2; i<=n; ++i ){
        printf("%d\n", parent[i]);
    }
}