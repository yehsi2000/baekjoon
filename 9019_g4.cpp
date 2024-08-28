#include <cstdio>
#include <string>
#include <queue>

using namespace std;

int D(int num){
    return (num<<1)%10000;
}

int S(int num){
    return num==0 ? 9999 : num-1;
}

int L(int num){
    return num*10 + (num/1000) - (num/1000)*10000;
}

int R(int num){
    return num/10 + (num%10)*1000;
}

queue<int> q;
queue<string>trace;

void bfs(int a, int b){
    bool visited[10000] = {};
    while(!q.empty()){
        int top = q.front();
        q.pop();
        string toptrace = trace.front();
        trace.pop();
        int d = D(top), s = S(top), l=L(top), r=R(top);

        //D
        if(d==b){
            printf("%sD\n",toptrace.c_str());
            return;
        } else if(!visited[d]){
            q.push(D(top));
            visited[d] = true;
            trace.push(toptrace+"D");
        }
        //S
        if(s==b){
            printf("%sS\n",toptrace.c_str());
            return;
        } else if(!visited[s]){
            q.push(S(top));
            visited[s] = true;
            trace.push(toptrace+"S");
        }
        //L
        if(l==b){
            printf("%sL\n",toptrace.c_str());
            return;
        } else if(!visited[l]){
            q.push(L(top));
            visited[l] = true;
            trace.push(toptrace+"L");
        }
        //R
        if(r==b){
            printf("%sR\n",toptrace.c_str());
            return;
        } else if(!visited[r]){
            q.push(R(top));
            visited[r] = true;
            trace.push(toptrace+"R");
        }
    }
    
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        q = queue<int>();
        trace = queue<string>();
        int a, b;
        scanf("%d %d", &a, &b);
        q.push(a);
        trace.push("");
        bfs(a, b);
    }
    return 0;
}