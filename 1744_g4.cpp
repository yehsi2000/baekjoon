#include <cstdio>
#include <queue>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    priority_queue<int> posq;
    priority_queue<int, vector<int>, greater<int>> negq;
    for(int i=0; i<n; ++i){
        int tmp;
        scanf("%d",&tmp);
        if(tmp>0) posq.push(tmp);
        else if(tmp<=0) negq.push(tmp);
    }
    
    int i, sum = 0;
    while(!posq.empty()){
        int first = posq.top();
        posq.pop();
        if(first>1 && !posq.empty()) {
            int second = posq.top();
            posq.pop();
            if(second>1){
                sum += first*second;
            } else {
                sum+=first;
                sum+=second;
            }
        } else {
            sum += first;
        }
    }
    while(!negq.empty()){
        int first = negq.top();
        negq.pop();
        if(!negq.empty()) {
            int second = negq.top();
            negq.pop();
            sum += first*second;
        } else {
            sum += first;
        }
    }
    printf("%d", sum);
}